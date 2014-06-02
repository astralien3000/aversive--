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

#ifndef EXTRACT_HPP
#define EXTRACT_HPP

//! \brief Extract a part of an integer...
/*!
  Actually I don't know why it was defined in aversive...
 */
template<typename ExtrType, char BYTE_OFFSET, typename BaseType>
inline ExtrType extract(BaseType v) {
  return (*(ExtrType*)((char*)(&v) + BYTE_OFFSET));
}

#endif//EXTRACT_HPP
