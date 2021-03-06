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
#include <hardware/architecture.hpp>

static bool initialized = false;
static bool running = false;
static int ret = 0;

//extern "C" void __cxa_pure_virtual(void) {
//  while(1);
//}

extern "C" volatile void* Default_Handler;

extern "C" void __aeabi_unwind_cpp_pr0(void) {
  //while(1);
  return;
}

extern "C" void __aeabi_unwind_cpp_pr1(void) {
  //while(1);
  return;
}

static void load_startup(void) __attribute__((optimize("O0")));
static void load_startup(void) {
  volatile void* test = Default_Handler;
  (void)test;
}

void Aversive::init(void) {
  load_startup();

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
