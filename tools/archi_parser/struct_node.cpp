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

#include "struct_node.hpp"

#include <sstream>

StructNode::StructNode(Identifier identifier) : _id(identifier) {
}

StructNode::StructNode(std::string identifier) : _id(identifier) {
}

StructNode::StructNode(int identifier) : _id(identifier) {
}

StructNode::StructNode(std::pair<std::string, int> identifier) : _id(identifier.first, identifier.second) {
}

StructNode::~StructNode(void) {

}

std::string StructNode::name(void) {
  return _id.name();
}

std::string StructNode::fullName(void) {
  if(parent()) {
    if(parent()->fullName() != "") {
      return parent()->fullName() + "::" + name();
    }
  }
  return name();
}

void StructNode::declare(indented_stream& out) {
  if(_id.isTemplate()) {
    out << "template<int param> ";
  }
  out << "struct " << _id.rawName() << ";" << std::endl;
}

void StructNode::define(indented_stream& out) {
  if(_id.isTemplate()) {
    out << "template<>" << std::endl;
  }
  out << "struct " << fullName() << " {" << std::endl;
  out.indentLevel()++;

  // Values
  if(!_values.empty()) {
    out << "enum {" << std::endl;
    out.indentLevel()++;
    for(auto kv = _values.begin() ; kv != _values.end() ; ++kv) {
      if(kv != _values.begin()) {
	out << "," << std::endl;
      }
      out << kv->first << " = " << kv->second;
    }
    out.indentLevel()--;
    out << std::endl << "};" << std::endl;
  }

  if(_children.size()) {
    if(!_values.empty()) out << std::endl;
    for(auto it = _children.begin() ; it != _children.end() ; ++it) {
      (*it)->declare(out);
    }
  }

  out.indentLevel()--;
  out << "};" << std::endl << std::endl;

  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    (*it)->define(out);
  }
}

void StructNode::defineValue(indented_stream& out) {
  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    (*it)->defineValue(out);
  }
}

