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

#ifndef STRUCT_NODE_HPP
#define STRUCT_NODE_HPP

#include "parent_node.hpp"
#include "child_node.hpp"

#include "identifier.hpp"

#include <map>

class StructNode : public ParentNode, public ChildNode {
public:
  StructNode(Identifier);
  StructNode(std::string);
  StructNode(int);
  StructNode(std::pair<std::string, int>);
  ~StructNode(void);

  virtual std::string name(void);
  virtual std::string fullName(void);

  virtual void declare(indented_stream&);
  virtual void define(indented_stream&);
  virtual void defineValue(indented_stream&);

private:
  Identifier _id;

protected:
  std::map<std::string, int> _values;
};

#endif//STRUCT_NODE_HPP
