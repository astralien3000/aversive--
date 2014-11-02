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

#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <string>
#include <sstream>

class Identifier {
private:
  bool _templated;
  int _val;
  std::string _str;

public:
  inline Identifier(std::string str) {
    _templated = false;
    _val = 0;
    _str = str;
  }

  inline Identifier(std::string str, int val) {
    _templated = true;
    _val = val;
    _str = str;
  }

  inline Identifier(int val) {
    _templated = true;
    _val = val;
    _str = std::string("value");
  }


  std::string name(void) {
    if(_templated) {
      std::stringstream oss;
      oss << _str << "<" << _val << ">";
      return oss.str();
    }
    return _str;
  }
  
  std::string rawName(void) {
    return _str;
  }

  bool isTemplate(void) {
    return _templated;
  }
};

#endif//IDENTIFIER_HPP
