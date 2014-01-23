#include <filter/pid_filter.hpp>
#include <filter/quadramp_filter.hpp>
#include <filter/diff_filter.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <filter/composed_filter.hpp>

#include <device/stream/uart_stream.hpp>
#include <math/safe_integer.hpp>

#include <device/eirbot2014/encoder.hpp>
#include <device/eirbot2014/motor.hpp>
#include <device/eirbot2014/odometer.hpp>
#include <device/eirbot2014/motor_controller.hpp>
#include <device/eirbot2014/robot_controller.hpp>

#include <math/vect.hpp>
#include <math/matrix.hpp>

//#include <hardware/uart.hpp>

#include <hardware/interrupts.hpp>

#define _ENC_R (*(volatile u32*)0x80A0)
#define _ENC_L (*(volatile u32*)0x8098)
#define _ENC_MOT_R (*(volatile u32*)0x8094)
#define _ENC_MOT_L (*(volatile u32*)0x809C)

#define _MOT_R (*(volatile s8*)0x8000)
#define _MOT_L (*(volatile s8*)0x8001)
#define _RESET_FPGA (*(volatile u8*)0x807F)

u32 ENC_L = _ENC_L;
u32 ENC_MOT_L = _ENC_MOT_L;
u32 INIT_ENC_L = 0;
u32 INIT_ENC_MOT_L = 0;
u32 ENC_R = _ENC_R;
u32 ENC_MOT_R = _ENC_MOT_R;
u32 INIT_ENC_R = 0;
u32 INIT_ENC_MOT_R = 0;
s32 MOT_L = _MOT_L;
s32 MOT_R = _MOT_R;

/*
void update(void) {
  ENC_L += MOT_L * 10;
  ENC_R += MOT_R * 8;
  //cout << "MOT_R " << MOT_R << endl;
}
*/

void update(void) {
  ENC_L = _ENC_L;
  ENC_R = -_ENC_R;
  
 _MOT_L = -(s8)MOT_L;
 _MOT_R = (s8)MOT_R;
}

class VidarBot {
private:
  typedef Encoder<&ENC_L> LeftEncoder;
  typedef Encoder<&ENC_R> RightEncoder;

  typedef Motor<&MOT_L> LeftMotor;
  typedef Motor<&MOT_R> RightMotor;

  typedef MotorController<LeftMotor, LeftEncoder, PidFilter, DiffFilter, PidFilter> LeftController;
  typedef MotorController<RightMotor, RightEncoder, PidFilter, DiffFilter, PidFilter> RightController;

  typedef Odometer<LeftEncoder, RightEncoder> MyOdometer;

  typedef RobotController<LeftController, RightController, MyOdometer, QuadrampFilter, PidFilter, PidFilter> MyRobot;

  // Devices
  LeftEncoder enc_l;
  RightEncoder enc_r;
  
  LeftMotor mot_l;
  RightMotor mot_r;  
  
  LeftController motc_l;
  RightController motc_r;

  MyOdometer odo;

  MyRobot robot;

  // Filters
  PidFilter id, pid_l, pid_r, pid_d, pid_a;
  DiffFilter diff_l, diff_r;
  QuadrampFilter qramp_d, qramp_a;

public:
  VidarBot(void) :
  enc_l("left encoder"), enc_r("right encoder"), 
  mot_l("left motor"), mot_r("right motor"),
  motc_l("left controller", mot_l, enc_l, id, diff_l, pid_l),
  motc_r("right controller", mot_r, enc_r, id, diff_r, pid_r),
  odo("odometer", enc_l, enc_r),
  robot("robot controller", motc_l, motc_r, odo, qramp_d, id, pid_d, qramp_a, id, pid_a)
  {

    id.setGains(1, 0, 0);

    // MotorControl
    diff_l.setDelta(39);
    pid_l.setGains(1, 0, 0);
    pid_l.setMaxIntegral(1000);
  
    diff_r.setDelta(39);
    pid_r.setGains(1, 0, 0);
    pid_r.setMaxIntegral(1000);

    // Odometer
    odo.setImpPerCm(100);
    odo.setDistEncoders(30);

    // Robot
    pid_a.setGains(50, 0, 0);
    pid_a.setMaxIntegral(1000);
  
    pid_d.setGains(1, 0, 0);
    pid_d.setMaxIntegral(1000);

    qramp_a.setFirstOrderLimit(1,1);
    qramp_a.setSecondOrderLimit(1,1);

    qramp_d.setFirstOrderLimit(1,1);
    qramp_d.setSecondOrderLimit(1,1);
  }
  
  void update(void) {
    Vect<2, s32> cmd;
    cmd.coord(0) = 100;
    cmd.coord(1) = 0;

    //motc_l.setValue(-80);
    //motc_r.setValue(-80);
    robot.setValue(cmd);

    //cout << "DIST = " << odo.distance() << " :: ANGLE = " << odo.angle() << endl;
  }
};

#define F_CPU 16000000l

#include <avr/io.h>
#include <util/delay.h>


VidarBot bot;

//int main(int argc, char* argv[]) {
bool robotInit() {
  XMCRA |= (1 << SRW11) | (1 << SRW00);
  MCUCR |= (1 << SRE);
  //reset  FPGA  
  _delay_ms(300);
  DDRB |= (1<<0); 
  _delay_ms(300);
  PORTB &= ~(1<<0);
  _delay_ms(300);
  _delay_ms(300);
  PORTB |= (1<<0);
  _delay_ms(300);
  PORTB &= ~(1<<0);
  _delay_ms(300);
  
  for(unsigned int i=0x8000;i<0x807F;i++) (*(volatile u8*)i) = 0;
  _RESET_FPGA = 255;
  _delay_ms(300);
  _RESET_FPGA =0;


  
  //_MOT_R = -60;
  //_MOT_L = 60;  
  //QuadrampFilter qr;
  //PidFilter fb, er;

  // fb.setGains(1,0,0);
  // er.setGains(1,0,0);
  // qr.setFirstOrderLimit(10,10);
  // qr.setSecondOrderLimit(1,1);
  //FeedbackLoopFilter<QuadrampFilter, MPidFilter, MPidFilter> cs(qr, fb, er);

  //OutputStream<255> cout;

  _MOT_R = 0;
  _MOT_L = 0;
  //Interrupts::set();

  /*
  INIT_ENC_L = _ENC_L;
  INIT_ENC_R = _ENC_R;
  INIT_ENC_MOT_L = _ENC_MOT_L;
  INIT_ENC_MOT_R = _ENC_MOT_R;
      _MOT_R = (s8) 10;
      _MOT_L = (s8) 10;
  */
  return true;
}

//  while(1) {
void robotLoop() {
  /* static int i;
  i++;
  if(i%100==0)
    UartStream<0>::instance() << "L>" << (s16)_MOT_L << " R>" << (s16)_MOT_R << "\n";
  //*/
  bot.update();
  update();
  _delay_ms(10);


#define MAX 30
  /*
    s32 test_r = (500 - (s32)_ENC_R/10) / 4;
    if(test_r > MAX) {
    _MOT_R = MAX;
    }
    else if(test_r < -MAX) {
    _MOT_R = -MAX;
    }
    else {
    _MOT_R = test_r;
    }
  */
  /*
    int32_t mencl = _ENC_MOT_L ;//- INIT_ENC_MOT_L;
    int32_t mencr = _ENC_MOT_R ;//- INIT_ENC_MOT_R;
    int32_t encl = _ENC_L ;//- INIT_ENC_L;
    int32_t encr = _ENC_R ;//- INIT_ENC_R;
  */
  //UartStream<0>::instance()  << "L:" << mencl << ")\t";
  //UartStream<0>::instance()  << "R:" << mencr << ")\t";
  /*
    UartStream<0>::instance()  << "L:" << encl ;//<< "(init:" << INIT_ENC_L << ")\t";
    UartStream<0>::instance()  << "R:" << encr ;//<< "(init:" << INIT_ENC_R << ")\n";
    UartStream<0>::instance() << "\n";
    //_delay_ms(1000);
   
    #define SPEED_L 30
    #define SPEED_R 30
    #define RANGE 100
    #define MRANGE -100
    if(encl > RANGE)
    _MOT_L = (s8) 1*SPEED_L;
    else if(encl < MRANGE)
    _MOT_L = (s8) -1*SPEED_L;
    else
    _MOT_L = (s8) 0;
    if(encr > RANGE)
    _MOT_R = (s8) 1*SPEED_R;
    else if(encr < MRANGE)
    _MOT_R = (s8) -1*SPEED_R;
    else
    _MOT_R = (s8) 0;
  
  
    s8 test_l = (s8) (-1*((s32)encl)/100);
    _MOT_L = -1*(encl/80);
  */
  /*if(test_l > MAX) {
    _MOT_L = MAX;
    }
    else if(test_l < -MAX) {
    _MOT_L = -MAX;
    }
    else {
    _MOT_L = test_l;
    }*/

}

void robotExit() {
}
