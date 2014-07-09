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

#include "register_node.hpp"

static std::map<int, int> _reg_by_size;

RegisterNode::RegisterNode(Identifier& identifier, int size)
  : SubRegisterNode(identifier)
{
  _values["SIZE"] = size;
  _values["REG"] = _reg_by_size[_values["SIZE"]]++;
}

RegisterNode::~RegisterNode(void) {
}

std::list<std::string>& RegisterNode::regs(void) {
  return _regs;
}

int RegisterNode::getRegSize(void) {
  return _values["SIZE"];
}

void RegisterNode::defineValue(indented_stream& out) {
  out << "template<> inline Register<" << _values["SIZE"] << ", " << _values["REG"] << ">";
  out << "::Register(void) : reg_size(" << _regs.size() << "), ";
  out << "reg{";
  
  for(auto it = _regs.begin() ; it != _regs.end() ; ++it) {
    if(it != _regs.begin()) {
      out << ", ";
    }
    out << "(u" << _values["SIZE"] << "*)&" << *it;
  }
  
  out << "} ";
  out << "{}" << std::endl;

  StructNode::defineValue(out);
}
