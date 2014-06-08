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

#include "uc_node.hpp"

#include "child_node.hpp"

UcNode::UcNode(std::string name) : _name(name) {
}

UcNode::~UcNode(void) {
}

std::string UcNode::name(void) {
  return _name;
}

std::string UcNode::fullName(void) {
  return std::string("");
}

void UcNode::declare(indented_stream& out) {
  out << "// Architecture : " << _name << std::endl;
}

void UcNode::define(indented_stream& out) {
  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->declare(out);
  }

  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->define(out);
  }
}

void UcNode::defineValue(indented_stream& out) {
  for(auto it = _children.begin() ; it != _children.end() ; it++) {
    (*it)->defineValue(out);
  }
}
