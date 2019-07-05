/*
 * File:   blink.c
 * Author: Dharmanshu Saini
 *
 * Created on 5 July, 2019, 1:39 PM
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>

#define LED RA0 // LED output PIN

void IOinit(){
    TRISA = 0; // Port A is Digital Output
    TRISC = 0; // Port C is Digital Output
    PORTA = 0;
    PORTC = 0;
}

void main(void) {
    IOinit();
    uint8_t i = 1;
    while(1){
        LED = i;
        i = ~i;
        __delay_ms(500);
    }
    return;
}
