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

#ifndef HARDWARE_EVENT_HPP
#define HARDWARE_EVENT_HPP

class HardwareEvent {
private:
  void (*_func)(void);

protected:
  //! \brief Default Constructor
  inline HardwareEvent(void) : _func(0) {}

public:
  //! \brief Set the function to call when interruption occurs
  //! \param func : A callable object which must be convertible into a "void (function*)(void)"
  template<typename Callable> inline void setFunction(Callable func) {
    _func = static_cast< void (*)(void) >(func);
  }

  //! \brief Unset the function to call when interruption occurs
  inline void unsetFunction(void) {
    _func = 0;
  }
  
  //! \brief Execute the function (only if there is one, of course)
  inline void execFunction(void) {
    if(_func) {
      _func();
    }
  }

  //! \brief Enable interruption for overflow event
  inline void start(void);
  //! \brief Disable interruption for overflow event
  inline void stop (void);

  //! \brief Returns true if the event is activ
  inline bool activated(void);
};

#endif//HARDWARE_EVENT_HPP
