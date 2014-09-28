/*
    Aversive++
    Copyright (C) 2014 Eirbot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MULTIPWM_HPP
#define MULTIPWM_HPP

#include <base/integer.hpp>
#include <base/singleton.hpp>
#include <container/list.hpp>
#include <device/output.hpp>

template<typename Config>
class MultiPWM : public Singleton<MultiPWM<Config>> {
  friend class Singleton<MultiPWM<Config>>;
  
private:
  MultiPWM(void);
  
private:
  class InternalPin {
  public:
    Output<bool>* _out;
    u32 _pwm;
    
  public:
    InternalPin(void)
      : _out(0), _pwm(0) {
    }
    
    InternalPin(Output<bool>& out)
      : _out(&out), _pwm(0) {
    }
    
    InternalPin& operator=(Output<bool>& out) {
      _out = &out;
      _pwm = 0;
      return *this;
    }
  };
  
 private:
  u32 _current;
  List<Config::MAX_PINS, InternalPin> _pins;
  
  inline void process(void) {
    for(int i = 0 ; i < _pins.usedSpace() ; i++) {
      if(_current >= _pins.get(i)._pwm) {
        _pins.get(i)._out->setValue(false);
      }
    }
    
    if(_current >= Config::PERIOD) {
      for(int i = 0 ; i < _pins.usedSpace() ; i++) {
        _pins.get(i)._out->setValue(true);
      }
      _current = 0;
    }
  }
  
 public:
  class Pin : public Output<u32> {
  protected:
    u32& _pwm;
    
  public:
    inline Pin(InternalPin& pin)
      : _pwm(pin._pwm) {
    }
    
    inline Pin(const Pin& other)
      : _pwm(other._pwm) {
    }
    
    inline void setValue(u32 val) {
      _pwm = val;
    }
  };
  
  Pin createPin(Output<bool>& out) {
    _pins.append(InternalPin(out));
    InternalPin& pin = _pins.get(_pins.usedSpace() - 1);
    return Pin(pin);
  }
};

struct DefaultMultiPWMConfig;

#endif//MULTIPWM_HPP
