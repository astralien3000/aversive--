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

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <base/integer.hpp>

#include <system/task.hpp>

//! \brief System to enable the robot to execute some tasks periodically, using interruptions
template<class Config>
class Scheduler {
public:
  //! \brief Default Constructor
  Scheduler(void);

  //! \brief Add a task to execute
  bool addTask(Task& tsk);
  
  //! \brief Remove a Task, it won't be executed anymore
  //! \warning The Task data is only removed from the scheduler at the next scheduler update, so you are not sure to be able to add a Task after that
  bool rmTask(Task& tsk);
  
  u16 freeSlot(void) const;
  
private:
  struct PrivateData;
  PrivateData _data;
};

//! \brief The default Scheduler Configuration structure
struct DefaultSchedulerConfig;

#endif//SCHEDULER_HPP
