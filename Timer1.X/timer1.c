/*
 * File:   timer1.c
 * Author: Dharmanshu Saini
 *
 * Created on 5 July, 2019, 2:01 PM
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

void timer1Init(){
    TMR1GE = 0; // Timer1 always on
    T1CKPS0 = 1; // Prescalar 1:8
    T1CKPS1 = 1;
    T1OSCEN = 0;
    TMR1CS = 0; // Use internal clock
    TMR1ON = 1; // Enable Timer1;
    TMR1L = 0; // Clear Count
    TMR1H = 0;
    TMR1IF = 0; // Clear Timer Flag
    TMR1IE = 1; // Enable Timer Interrupt
    PEIE = 1; // Enable Peripheral Interrupt
    GIE = 1; // Enable global interrupt
}

void main(void) {
    IOinit();
    timer1Init();
    while(1);
    return;
}

void __interrupt() ISR(){
    if(TMR1IF){
        LED = i;
        i = ~i;
        TMR1L = 0;
        TMR1H = 0;
        TMR1IF = 0;
    }
}