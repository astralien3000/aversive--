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

#ifndef SASIAE_SCHEDULER_HPP
#define SASIAE_SCHEDULER_HPP

#include <system/scheduler.hpp>
#include <aversive.hpp>
#include <client_thread.hpp>

struct DefaultSchedulerConfig {
  static constexpr u32 MAX_TASKS = 8;
};

template<class Config>
Scheduler<Config>::Scheduler(void) {
  Aversive::init();
  _current = 0;

  ClientThread::instance().setSyncFunction([&](long long t){
    _current = t;
    processTasks();
  });
}

template<class Config>
inline void Scheduler<Config>::lock(void) {

}

template<class Config>
inline void Scheduler<Config>::unlock(void) {

}


#endif//SASIAE_SCHEDULER_HPP
