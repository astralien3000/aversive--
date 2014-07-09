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

#include "config_node.hpp"

static std::map<int, int> _conf_by_size;

ConfigNode::ConfigNode(Identifier& identifier)
  : SubRegisterNode(identifier)
{
}

void ConfigNode::setParent(ParentNode* p) {
  SubRegisterNode::setParent(p);
  _values["SIZE"] = getRegSize();
  _values["CONFIG"] = _conf_by_size[_values["SIZE"]]++;
}

ConfigNode::~ConfigNode(void) {
}

std::list<std::string>& ConfigNode::confs(void) {
  return _confs;
}

void ConfigNode::defineValue(indented_stream& out) {
  out << "template<> inline Config<" << _values["SIZE"] << ", " << _values["CONFIG"] << ">";
  out << "::Config(void) : ";
  out << "conf{";
  
  for(auto it = _confs.begin() ; it != _confs.end() ; ++it) {
    if(it != _confs.begin()) {
      out << ", ";
    }
    out << *it;
  }
  
  out << "} ";
  out << "{}" << std::endl;

  StructNode::defineValue(out);
}
