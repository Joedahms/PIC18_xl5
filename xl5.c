#define _XTAL_FREQ 4000000  // also defined in main

#include <xc.h>

#include "xl5.h"

void init_XL5()
{
    TRISB0 = 0;         // output
    LATBbits.LATB0 = 0; // start 0
    LATBbits.LATB0 = 1; // set high
    __delay_ms(70);     // delay 70 ms
    LATBbits.LATB0 = 0; // set low
    __delay_ms(412);    // delay 412 ms
}

void throttle_test()
{
    /*
    // PWM setup
    PTCKPS0 = 1;            // time base 1:64 prescale
    PTCKPS1 = 1;
    
    //PTPER = 155;          // PWM period of 10ms
    PTPERL = 0b10011011;
    PTPERH = 0b00000000;
     * 
     */

    PTEN = 1;               // PWM time base is on 
    
    PDC0L = 0b01011111;     // neutral throttle +1.5 -8.5
    
    __delay_ms(1000);
    PDC0L = 0b10000000;     // full throttle +2 -8
    __delay_ms(2000);
    PDC0L = 0b01011111;     // neutral throttle +1.5 -8.5
    __delay_ms(2000);
    PDC0L = 0b01000000;     // full reverse +1 -9
    __delay_ms(1000);
    PDC0L = 0b01011111;     // neutral throttle +1.5 -8.5
    __delay_ms(1000);
    PDC0L = 0b01000000;     // full reverse +1 -9
    __delay_ms(2000);
    PDC0L = 0b01011111;     // neutral throttle +1.5 -8.5
     
}
