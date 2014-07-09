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

#include "parent_node.hpp"

#include "child_node.hpp"

ParentNode::ParentNode(void) {
}

ParentNode::~ParentNode(void) {
  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    delete *it;
    _children.erase(it);
  }
}

void ParentNode::addChild(ChildNode* nod) {
  // if no parent
  if(! nod->parent()) {
    _children.insert(nod);
  }
  else {
    // ERROR !
  }
}

bool ParentNode::isChild(ChildNode* nod) {
  for(auto it = _children.begin() ; it != _children.end() ; ++it) {
    if(nod == *it) {
      return true;
    }
  }
  return false;
}
