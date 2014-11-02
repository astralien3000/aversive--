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

#ifndef ADM2560_HPP
#define ADM2560_HPP

#include <micro/avr.hpp>

//! \class ADM2560 adm2560.hpp <board/adm2560.hpp>
//! \brief Class providing meta-data for the Arduino Mega 2560 board.
class ADM2560 {
  //! \brief Private default constructor to prevent instanciation.
  ADM2560();
  
public:
  //! \class ADM2560::Pinmap adm2560.hpp <board/adm2560.hpp>
  //! \brief Pinmap for Arduino Mega 2560 board. D stands for digital pins and A for analog pins.
  class Pinmap {
    //! \brief Private default constructor to prevent instanciation.
    Pinmap();
    
  public:
    static constexpr int D0  = AVR::pin('e', 0);
    static constexpr int D1  = AVR::pin('e', 1);
    static constexpr int D2  = AVR::pin('e', 4);
    static constexpr int D3  = AVR::pin('e', 5);
    static constexpr int D4  = AVR::pin('g', 5);
    static constexpr int D5  = AVR::pin('e', 3);
    static constexpr int D6  = AVR::pin('h', 3);
    static constexpr int D7  = AVR::pin('h', 4);
    static constexpr int D8  = AVR::pin('h', 5);
    static constexpr int D9  = AVR::pin('h', 6);
    static constexpr int D10 = AVR::pin('b', 4);
    static constexpr int D11 = AVR::pin('b', 5);
    static constexpr int D12 = AVR::pin('b', 6);
    static constexpr int D13 = AVR::pin('b', 7);
    static constexpr int D14 = AVR::pin('j', 1);
    static constexpr int D15 = AVR::pin('j', 0);
    static constexpr int D16 = AVR::pin('h', 1);
    static constexpr int D17 = AVR::pin('h', 0);
    static constexpr int D18 = AVR::pin('d', 3);
    static constexpr int D19 = AVR::pin('d', 2);
    static constexpr int D20 = AVR::pin('d', 1);
    static constexpr int D21 = AVR::pin('d', 0);
    static constexpr int D22 = AVR::pin('a', 0);
    static constexpr int D23 = AVR::pin('a', 1);
    static constexpr int D24 = AVR::pin('a', 2);
    static constexpr int D25 = AVR::pin('a', 3);
    static constexpr int D26 = AVR::pin('a', 4);
    static constexpr int D27 = AVR::pin('a', 5);
    static constexpr int D28 = AVR::pin('a', 6);
    static constexpr int D29 = AVR::pin('a', 7);
    static constexpr int D30 = AVR::pin('c', 7);
    static constexpr int D31 = AVR::pin('c', 6);
    static constexpr int D32 = AVR::pin('c', 5);
    static constexpr int D33 = AVR::pin('c', 4);
    static constexpr int D34 = AVR::pin('c', 3);
    static constexpr int D35 = AVR::pin('c', 2);
    static constexpr int D36 = AVR::pin('c', 1);
    static constexpr int D37 = AVR::pin('c', 0);
    static constexpr int D38 = AVR::pin('d', 7);
    static constexpr int D39 = AVR::pin('g', 2);
    static constexpr int D40 = AVR::pin('g', 1);
    static constexpr int D41 = AVR::pin('g', 0);
    static constexpr int D42 = AVR::pin('l', 7);
    static constexpr int D43 = AVR::pin('l', 6);
    static constexpr int D44 = AVR::pin('l', 5);
    static constexpr int D45 = AVR::pin('l', 4);
    static constexpr int D46 = AVR::pin('l', 3);
    static constexpr int D47 = AVR::pin('l', 2);
    static constexpr int D48 = AVR::pin('l', 1);
    static constexpr int D49 = AVR::pin('l', 0);
    static constexpr int D50 = AVR::pin('b', 3);
    static constexpr int D51 = AVR::pin('b', 2);
    static constexpr int D52 = AVR::pin('b', 1);
    static constexpr int D53 = AVR::pin('b', 0);
    
    static constexpr int A0  = AVR::pin('f', 0);
    static constexpr int A1  = AVR::pin('f', 1);
    static constexpr int A2  = AVR::pin('f', 2);
    static constexpr int A3  = AVR::pin('f', 3);
    static constexpr int A4  = AVR::pin('f', 4);
    static constexpr int A5  = AVR::pin('f', 5);
    static constexpr int A6  = AVR::pin('f', 6);
    static constexpr int A7  = AVR::pin('f', 7);
    static constexpr int A8  = AVR::pin('k', 0);
    static constexpr int A9  = AVR::pin('k', 1);
    static constexpr int A10 = AVR::pin('k', 2);
    static constexpr int A11 = AVR::pin('k', 3);
    static constexpr int A12 = AVR::pin('k', 4);
    static constexpr int A13 = AVR::pin('k', 5);
    static constexpr int A14 = AVR::pin('k', 6);
    static constexpr int A15 = AVR::pin('k', 7);
  };
};

#endif//ADM2560PINMAP_HPP
