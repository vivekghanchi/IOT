#include "mbed.h"

AnalogIn pot(PTB0);
AnalogIn ldr(PTB1);
Serial pc(USBTX, USBRX);
float i,j;

main()
{
    while(1)
    {
    i=pot.read();
    j=ldr.read();
    pc.printf("pot & ldr value = %0.2f = %0.2f\n\r",i,j);    
    wait(1);
    }
}