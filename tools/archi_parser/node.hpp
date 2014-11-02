/*
    Aversive++                                                           
    Copyright (C) 2014 astralien3000                                            
                                                                         
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

#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include "indented_stream.hpp"

class Node {
public:
  virtual ~Node(void) {}

  virtual std::string name(void) = 0;
  virtual std::string fullName(void) = 0;

  virtual void declare(indented_stream&) = 0;
  virtual void define(indented_stream&) = 0;
  virtual void defineValue(indented_stream&) = 0;
};

#endif//NODE_HPP
