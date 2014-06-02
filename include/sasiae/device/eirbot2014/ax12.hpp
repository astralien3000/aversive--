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

#ifndef SASIAE_AX12_HPP
#define SASIAE_AX12_HPP

#include <base/integer.hpp>
#include <QStringList>
#include <QString>
#include <client_thread.hpp>
#include <sstream>

struct AX12PrivateData{
  u16 angle;
  u16 speed;
  u16 torque;
  WorkingMode wm;
  ComMode cm;
};

#include "../../../common/device/eirbot2014/ax12.hpp"

#endif//SASIAE_AX12_HPP
