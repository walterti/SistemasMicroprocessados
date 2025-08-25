#define _XTAL_FREQ 2000000
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
#include "lcd.h"
#include <stdio.h>
#include <string.h>
int cont1505474 = 0; //contador, utilizado também como identificação pessoal
char resultado[2] = {}; //caracteres que serão escritos no LCD, até 99(dois dígitos)
void atualizaLCD(){
    LCD_limpa();
    sprintf(resultado, "%d", cont1505474); //converte o número para caracteres
    for(int i = 0; i < strlen(resultado); i++){ //escreve cada caractere que compõe o numero no LCD
        LCD_escreve(resultado[i]);
    }
}
void verificaBotao()
{
    if(RB0 == 0){
        __delay_ms(1500); //atraso para evitar pressionamentos múltiplos
        if(cont1505474 < 99){ //caso seja menor que 99 incrementa o contador
            cont1505474++;
        }
        else{ // caso contrário zera
            cont1505474 = 0;
        }
        atualizaLCD();
    }
}
void main(){
    TRISB = 0b00000001;
    OPTION_REGbits.nRBPU = 0;
    LCD_init();
    atualizaLCD();
    while(1){
        verificaBotao();
    }
}
