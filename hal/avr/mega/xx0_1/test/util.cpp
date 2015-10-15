#include <base/integer.hpp>

void delay(void) {
    for(volatile u16 i = 0 ; i < 0xFFFF ; i++);
}
