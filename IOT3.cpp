#include "mbed.h"

PwmOut ledp (PTB18);
float i;

main()
{
    ledp.period_ms(3);
    
    while(1)
    {
        for (i=1;i>=0;i=i-0.01)
        {
            ledp.write(i);
            wait(0.02);
        }    
        for (i=0;i<=1;i=i+0.01)
        {
            ledp.write(i);
            wait(0.02);
        } 
    }   
} 
