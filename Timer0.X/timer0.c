/*
 * File:   timer0.c
 * Author: Dharmanshu Saini
 *
 * Created on 5 July, 2019, 1:51 PM
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>

#define LED RA0
uint8_t i = 1;

void IOinit(){
    TRISA = 0; // Port A is Digital Output
    TRISC = 0; // Port C is Digital Output
    PORTA = 0; // Clear PORTA
    PORTC = 0; // Clear PORTC
}

void timer0Init(){
    T0CS = 0; // Use Internal Clock
    T0SE = 0; // Increment on low to High
    PSA = 0; // Use Prescaler assigned to Timer0 Module
    PS0 = 1; // Prescaler = 111 = 1:256
    PS1 = 1;
    PS2 = 1;
    TMR0 = 0; // Clear Count
    T0IF = 0; // Clear Timer0 Interrupt flag
    T0IE = 1; // Enable Timer0 Interrrupt
    PEIE = 1; // Enable Peripheral Interrupt
    GIE = 1; // Enable Global Interrupt
}

void main(void) {
    IOinit();
    timer0Init();
    while(1);
    return;
}

void __interrupt() ISR(){
    if(T0IF){
        LED = i;
        i = ~i;
        TMR0 = 0;
        T0IF = 0;
    }
}
