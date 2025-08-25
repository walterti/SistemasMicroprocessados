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

void main(){
    TRISD = 0b00000000;//Define a porta D como saída de dados
    unsigned char PORT1505474 = 0b11111111; //Variável inserida para atender ao requisito de identificação pessoal
    PORTB = PORT1505474; //Apaga todos os leds
    while(1){
        PORTD = 0b01111110;//Acende os leds 1 e 8
        __delay_ms(1000);
        PORTD = PORT1505474;
        PORTD = 0b10111101;//Acende os leds 2 e 7
        __delay_ms(1000);
        PORTD = PORT1505474;
        PORTD = 0b11011011; //Acende os leds 3 e 6
        __delay_ms(1000);
        PORTD = PORT1505474;
        PORTD = 0b11100111;//Acende os leds 4 e 5
        __delay_ms(1000);
        PORTD = PORT1505474;
        PORTD = 0b11011011;//Acende os leds 3 e 6
        __delay_ms(1000);
        PORTD = PORT1505474;
        PORTD = 0b10111101;//Acende os leds 2 e 7
        __delay_ms(1000);
        PORTD = PORT1505474;
    }
}
