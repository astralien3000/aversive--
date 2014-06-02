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

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

//! \class Singleton singleton.hpp <base/singleton.hpp>
//! \brief Interface for classes that should have only one instance.
//! \param _BASE : The class that should have only one instance.
template<typename _BASE>
class Singleton {
protected:
  //! \brief Protected default constructor, to avoid instanciation.
  inline Singleton(void) {
  }
  
  //! \brief Protected copy constructor, to avoid copy construction.
  inline Singleton(const Singleton&) {
  }
  
public:
  //! \brief Access to the single instance of the class.
  //! \return A reference to the instance.
  static inline _BASE& instance(void) {
    static _BASE inst;
    return inst;
  }
};

#endif//SINGLETON_HPP
