#define _XTAL_FREQ 4000000

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <pic16f877a.h>
#include "uart.h"

void main(){
    int walter1505474 = 1; // Variável com o nome e RU
    unsigned char recebido;
    TRISD = 0b00000000;
    PORTD = 0b11111111;
    UART_Init(9600);
    while(walter1505474){
        if(UART_Data_Ready()){
            recebido = UART_Read();
            if(recebido == 'a'){
                PORTD = 0b11111110;
            }
            else if(recebido == 'b'){
                PORTD = 0b10111111;
            }
            else if(recebido == 'c'){
                PORTD = 0b11110000;
            }
            else if(recebido == 'd'){
                PORTD = 0b00000000;
            }
            else if(recebido == 's'){
                PORTD = 0b11111111;
            }
        }
    }
}