#include <filter/pid_filter.hpp>
#include <filter/quadramp_filter.hpp>
#include <filter/diff_filter.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <filter/composed_filter.hpp>

#include <math/safe_integer.hpp>

#include <device/eirbot2014/encoder.hpp>
#include <device/eirbot2014/motor.hpp>
#include <device/eirbot2014/odometer.hpp>
#include <device/eirbot2014/motor_controller.hpp>
#include <device/eirbot2014/robot_controller.hpp>

#include <math/vect.hpp>
#include <math/matrix.hpp>

#include <hardware/uart.hpp>

#define _ENC_L (*(volatile u32*)0x80A0)
#define _ENC_R (*(volatile u32*)0x8094)

#define _MOT_L (*(volatile u8*)0x8000)
#define _MOT_R (*(volatile u8*)0x8001)

u32 ENC_L = _ENC_L;
u32 ENC_R = _ENC_R;
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
  ENC_R = _ENC_R;

  _MOT_L = -(u8)MOT_L;
  _MOT_R = (u8)MOT_R;
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
    diff_l.setDelta(10);
    pid_l.setGains(10, 0, 0);
    pid_l.setMaxIntegral(1000);
  
    diff_r.setDelta(10);
    pid_r.setGains(10, 0, 0);
    pid_r.setMaxIntegral(1000);

    // Odometer
    odo.setImpPerCm(100);
    odo.setDistEncoders(30);

    // Robot
    pid_a.setGains(100, 15, 100);
    pid_a.setMaxIntegral(1000);
  
    pid_d.setGains(1000, 10, 800);
    pid_d.setMaxIntegral(1000);

    qramp_a.setFirstOrderLimit(70,70);
    qramp_a.setSecondOrderLimit(3,3);

    qramp_d.setFirstOrderLimit(70,70);
    qramp_d.setSecondOrderLimit(3,3);
  }
  
  void update(void) {
    Vect<2, s32> cmd;
    cmd.coord(0) = 0;
    cmd.coord(1) = 0;

    motc_l.setValue(50);
    motc_r.setValue(50);

    //cout << "DIST = " << odo.distance() << " :: ANGLE = " << odo.angle() << endl;
  }
};

#define F_CPU 16000000l

#include <avr/io.h>
#include <util/delay.h>


template<int SIZE>
class OutputStream {
protected:
  Array<SIZE, char> buff;
  int i = 0;
public:
  OutputStream(void) {
    Uart<0>::instance().init();
  }
  
  void setOutput(const Array<SIZE, char>& ar) {
    buff = ar;
  }

  OutputStream<SIZE>& operator<<(const char* str) {
    const char* it = str;
    while((*it) != '\0' && i < SIZE) {
      buff[i] = *it;
      i++;
      if(*it == '\n') {
	buff[i] = '\0';
	flushOutput();
      }
      it++;
    }
    buff[i] = '\0';
    return (*this);
  }

  template<typename T>
  OutputStream<SIZE>& operator<<(T val) {
    int beg = i;
    while(val != 0 && i < SIZE) {
      buff[i] = '0' + (val % 10);
      val /= 10;
      i++;
    }
    
    for(int j = 0; j <= (i-beg-1)/2 ; j++) {
      char aux = buff[beg + j];
      buff[beg + j] = buff[i - j - 1];
      buff[i - j - 1] = aux;
    }
    buff[i] = '\0';
    return (*this);
  }

  void flushOutput(void) {
    for(int j = 0 ; j < SIZE && buff[j] != '\0' ; j++) {
      Uart<0>::instance().send(buff[j]);
    }
    i = 0;
  }
};



int main(int argc, char* argv[]) {
  _delay_ms(1000);
  XMCRA |= (1 << SRW11) | (1 << SRW00);
  MCUCR |= (1 << SRE);
  _delay_ms(300);  
  DDRB = 1;
  PORTB = 0;
  _delay_ms(300);
  PORTB = 1; // RESET ??
  _delay_ms(300);
  PORTB = 0; // RESET ??
  _delay_ms(300);

  //VidarBot bot;

  //_MOT_R = -60;
  //_MOT_L = 60;  
  QuadrampFilter qr;
  PidFilter fb, er;

  // fb.setGains(1,0,0);
  // er.setGains(1,0,0);
  // qr.setFirstOrderLimit(10,10);
  // qr.setSecondOrderLimit(1,1);
  //FeedbackLoopFilter<QuadrampFilter, MPidFilter, MPidFilter> cs(qr, fb, er);

  OutputStream<255> cout;

  _MOT_R = 20;

  while(1) {
    //uart.send('v');
  //for(int i = 0 ; i < 100 ; i++) {
    //bot.update();
    //update();

    #define MAX 100
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
    //*/
    cout << _ENC_L << "\n";
    s32 test_l = (500 - ((s32)_ENC_L)/10) / 4;
    if(test_l > MAX) {
      _MOT_L = MAX;
    }
    else if(test_l < -MAX) {
      _MOT_L = -MAX;
    }
    else {
      _MOT_L = test_l;
    }

  }

  return 0;
}
