#include "mbed.h"

BusOut myled(LED1, LED2, LED3);

int main() {
    while(1) {
        myled = 0x3;
        wait(0.2);
        myled = 0x4;
        wait(0.2);
         myled = 0x7;
        wait(0.2);
    }
}
