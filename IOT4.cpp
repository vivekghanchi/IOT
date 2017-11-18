#include "mbed.h"


BusOut myled(PTB18, PTB19, PTD1);
AnalogIn pot(PTB0);

main ()
{
    while(1)
    {
        if ((pot.read()>=0) & (pot.read()<0.33))
        {
            myled=0x6;
        }
        else if ((pot.read()>=0.33) & (pot.read()<0.66))
        {
            myled=0x5;
        }    
        else if ((pot.read()>=0.66) & (pot.read()<=1))
        {
            myled=0x3;
        }        
    }    
}
