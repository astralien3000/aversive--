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

#ifndef CHILD_NODE_HPP
#define CHILD_NODE_HPP

#include "node.hpp"

class ParentNode;

class ChildNode : virtual public Node {
public:
  ChildNode(void);

  virtual ~ChildNode(void);

  virtual void setParent(ParentNode*);
  ParentNode* parent(void);

private:
  ParentNode* _parent;
};

#endif//PARENT_NODE_HPP
