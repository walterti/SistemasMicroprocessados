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

int walter1505474 = 1; // Variável inserida para atender ao requisito de identificação pessoal


// Inicialização do ADC
void ADC_Init(void) {
    ADCON0 = 0b10010101;
    ADCON1 = 0b11000000;
}

// Função para ler o valor do ADC no pino RA2 (AN2)
int ReadADC_RA2() {
    __delay_ms(2); // Tempo de aquisição do sinal
    GO_nDONE = 1; // Inicia a conversão
    while(GO_nDONE); // Espera terminar a conversão
    return ((ADRESH << 8) + ADRESL); // Retorna o valor de 0 a 1023
}

void main(void) {
    ADC_Init(); // Inicializa o conversor analógico-digital
    TRISD = 0b00000000; // Define a porta D como saída de dados
    PORTD = 0b11111111; // Apaga todos os leds
    while(walter1505474) {
        int valor = ReadADC_RA2();
        if(valor <= 676){ // Caso a luminosidade esteja abaixo do limiar
            PORTDbits.RD0 = 0; // Acende o led na porta D0
        }
        else{ //Caso a luminosidade aumente
            PORTDbits.RD0 = 1; // Apaga o led na porta D0
        }
    }
}