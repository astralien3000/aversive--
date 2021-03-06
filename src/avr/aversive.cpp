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

#include <aversive.hpp>

static bool initialized = false;
static bool running = false;
static int ret = 0;

extern "C" {
__extension__ typedef int __guard __attribute__((mode (__DI__)));

int __cxa_guard_acquire(__guard *g) __attribute__((weak));
int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);}

void __cxa_guard_release (__guard *g) __attribute__((weak));
void __cxa_guard_release (__guard *g) {*(char *)g = 1;}

void __cxa_guard_abort (__guard *) __attribute__((weak));
void __cxa_guard_abort (__guard *) {}

void __cxa_pure_virtual(void) __attribute__((weak));
void __cxa_pure_virtual(void) {}
}

void Aversive::init(void) {
  if(!initialized) {
    running = initialized = true;
  }
}

bool Aversive::sync(void) {
  return Aversive::isRunning();
}

void Aversive::sleep(int ms) {
  (void) ms;
}

void Aversive::stop(void) {
  running = false;
}

int Aversive::exit(void) {
  Aversive::stop();
  return ret;
}

bool Aversive::isInitialized(void) {
  return initialized;
}

bool Aversive::isRunning(void) {
  return running;
}

int Aversive::returnCode(void) {
  return ret;
}

void Aversive::setReturnCode(int returnCode) {
  ret = returnCode;
}
