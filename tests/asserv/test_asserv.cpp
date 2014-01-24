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
#include <hardware/timer.hpp>

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

public:
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
    diff_l.setDelta(1);
    pid_l.setGains(800, 0, 0);
    pid_l.setMaxIntegral(1000);
    pid_l.setOutShift(11);

    diff_r.setDelta(1);
    pid_r.setGains(800, 0, 0);
    pid_r.setMaxIntegral(1000);
    pid_r.setOutShift(11);

    // Odometer
    odo.setImpPerCm(100);
    odo.setDistEncoders(15);

    // Robot
    pid_a.setGains(1000, 10, 800);
    pid_a.setMaxIntegral(10000);
    pid_a.setOutShift(6);
  
    pid_d.setGains(1000, 15, 100);
    pid_d.setMaxIntegral(2000);
    pid_d.setOutShift(8);

    qramp_a.setFirstOrderLimit(2,2);
    qramp_a.setSecondOrderLimit(1,1);

    qramp_d.setFirstOrderLimit(2,2);
    qramp_d.setSecondOrderLimit(1,1);
  }
  
  Vect<2, s32> cmd;

  void update(void) {
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


u16 i = 0;

void asserv_update(void) {
  if(i++ % 8 == 0) {
    bot.update();
    update();
  }
}

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

  _MOT_R = 0;
  _MOT_L = 0;

  bot.cmd.coord(0) = -100;
  bot.cmd.coord(1) = 20;

  Timer<0>& timer = Timer<0>::instance();
  timer.init();
  timer.setPrescaler<8>();
  Timer<0>::OverflowEvent& evt = timer.overflowEvent();
  evt.setFunction([]() {
      if(i++ % 15 == 0) {
	bot.update();
	update();
      }

      if(i%2000== 0) {
	//bot.cmd.coord(1) += 1;
      }
    });
  evt.start();

  Interrupts::set();
  return true;
}

void robotLoop() {
  /* static int i;
  i++;
  if(i%100==0)
    UartStream<0>::instance() << "L>" << (s16)_MOT_L << " R>" << (s16)_MOT_R << "\n";
  //*/	
  
  //bot.update();
  //update();
  //_MOT_R = 40;
  //_MOT_L = 40;
  _delay_ms(10);
}

void robotExit() {
}
