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

static inline constexpr int __ADM2560Pin(char p, char bit) {
  return ((int) ((p >= 'j' ? p - 1 : p) - 'a')) * 8 + bit;
}

//! \class ADM2560Pinmap adm2560.hpp <device/pin/board/adm2560.hpp>
//! \brief Pinmap for Arduino Mega 2560 board. D stands for digital pins and A for analog pins.
class ADM2560Pinmap {
  //! \breif Private default constructor to prevent instanciation.
  ADM2560Pinmap();
  
public:
  static constexpr int D0  = __ADM2560Pin('e', 0);
  static constexpr int D1  = __ADM2560Pin('e', 1);
  static constexpr int D2  = __ADM2560Pin('e', 4);
  static constexpr int D3  = __ADM2560Pin('e', 5);
  static constexpr int D4  = __ADM2560Pin('g', 5);
  static constexpr int D5  = __ADM2560Pin('e', 3);
  static constexpr int D6  = __ADM2560Pin('h', 3);
  static constexpr int D7  = __ADM2560Pin('h', 4);
  static constexpr int D8  = __ADM2560Pin('h', 5);
  static constexpr int D9  = __ADM2560Pin('h', 6);
  static constexpr int D10 = __ADM2560Pin('b', 4);
  static constexpr int D11 = __ADM2560Pin('b', 5);
  static constexpr int D12 = __ADM2560Pin('b', 6);
  static constexpr int D13 = __ADM2560Pin('b', 7);
  static constexpr int D14 = __ADM2560Pin('j', 1);
  static constexpr int D15 = __ADM2560Pin('j', 0);
  static constexpr int D16 = __ADM2560Pin('h', 1);
  static constexpr int D17 = __ADM2560Pin('h', 0);
  static constexpr int D18 = __ADM2560Pin('d', 3);
  static constexpr int D19 = __ADM2560Pin('d', 2);
  static constexpr int D20 = __ADM2560Pin('d', 1);
  static constexpr int D21 = __ADM2560Pin('d', 0);
  static constexpr int D22 = __ADM2560Pin('a', 0);
  static constexpr int D23 = __ADM2560Pin('a', 1);
  static constexpr int D24 = __ADM2560Pin('a', 2);
  static constexpr int D25 = __ADM2560Pin('a', 3);
  static constexpr int D26 = __ADM2560Pin('a', 4);
  static constexpr int D27 = __ADM2560Pin('a', 5);
  static constexpr int D28 = __ADM2560Pin('a', 6);
  static constexpr int D29 = __ADM2560Pin('a', 7);
  static constexpr int D30 = __ADM2560Pin('c', 7);
  static constexpr int D31 = __ADM2560Pin('c', 6);
  static constexpr int D32 = __ADM2560Pin('c', 5);
  static constexpr int D33 = __ADM2560Pin('c', 4);
  static constexpr int D34 = __ADM2560Pin('c', 3);
  static constexpr int D35 = __ADM2560Pin('c', 2);
  static constexpr int D36 = __ADM2560Pin('c', 1);
  static constexpr int D37 = __ADM2560Pin('c', 0);
  static constexpr int D38 = __ADM2560Pin('d', 7);
  static constexpr int D39 = __ADM2560Pin('g', 2);
  static constexpr int D40 = __ADM2560Pin('g', 1);
  static constexpr int D41 = __ADM2560Pin('g', 0);
  static constexpr int D42 = __ADM2560Pin('l', 7);
  static constexpr int D43 = __ADM2560Pin('l', 6);
  static constexpr int D44 = __ADM2560Pin('l', 5);
  static constexpr int D45 = __ADM2560Pin('l', 4);
  static constexpr int D46 = __ADM2560Pin('l', 3);
  static constexpr int D47 = __ADM2560Pin('l', 2);
  static constexpr int D48 = __ADM2560Pin('l', 1);
  static constexpr int D49 = __ADM2560Pin('l', 0);
  static constexpr int D50 = __ADM2560Pin('b', 3);
  static constexpr int D51 = __ADM2560Pin('b', 2);
  static constexpr int D52 = __ADM2560Pin('b', 1);
  static constexpr int D53 = __ADM2560Pin('b', 0);

  static constexpr int A0  = __ADM2560Pin('f', 0);
  static constexpr int A1  = __ADM2560Pin('f', 1);
  static constexpr int A2  = __ADM2560Pin('f', 2);
  static constexpr int A3  = __ADM2560Pin('f', 3);
  static constexpr int A4  = __ADM2560Pin('f', 4);
  static constexpr int A5  = __ADM2560Pin('f', 5);
  static constexpr int A6  = __ADM2560Pin('f', 6);
  static constexpr int A7  = __ADM2560Pin('f', 7);
  static constexpr int A8  = __ADM2560Pin('k', 0);
  static constexpr int A9  = __ADM2560Pin('k', 1);
  static constexpr int A10 = __ADM2560Pin('k', 2);
  static constexpr int A11 = __ADM2560Pin('k', 3);
  static constexpr int A12 = __ADM2560Pin('k', 4);
  static constexpr int A13 = __ADM2560Pin('k', 5);
  static constexpr int A14 = __ADM2560Pin('k', 6);
  static constexpr int A15 = __ADM2560Pin('k', 7);
};

#endif//ADM2560_HPP
