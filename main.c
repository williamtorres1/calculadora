/*****************************************
*   File:   Calculadora.c                *
*   Author: William Torres               *
*           Arthur Brito                 *
*           Gabriel Pedro                *
*           Ruann Teixeira               *
******************************************/

#include <xc.h>
#include "math.h"
#include "meu_lcd16x2.c"
#ifndef _XTAL_FREQ
#define _XTAL_FREQ  4000000
#endif
struct teclas_calculadora
{
    int sete;
    int quatro;
    int um;
    int on_clear;
    int oito;
    int cinco;
    int dois;
    int zero;
    int nove;
    int seis;
    int tres;
    int igual;
    int divisao;
    int multi;
    int menos;
    int mais;
}tecla;
int TECLA2 = 80;

void definirPORTAS()
{
    //Definir portas da calculadora como entrada
	TRISAbits.TRISA0 = 0;  	
	TRISAbits.TRISA1 = 0;   
	TRISAbits.TRISA2 = 0;   
	TRISAbits.TRISA3 = 0;
    
    //portas como saída
	TRISAbits.TRISA4 = 1;   
	TRISAbits.TRISA5 = 1;
    TRISAbits.TRISA6 = 1;   
    TRISAbits.TRISA7 = 1;
    
	// Configura Portas do display LCD
    TRISDbits.TRISD0 = 0;  	
    TRISDbits.TRISD1 = 0;  	
    TRISDbits.TRISD2 = 0;  
    TRISDbits.TRISD3 = 0;  	
    TRISDbits.TRISD4 = 0;  	
    TRISDbits.TRISD5 = 0;  	
    TRISDbits.TRISD6 = 0;  	
    TRISDbits.TRISD7 = 0;  	
    TRISEbits.TRISE0 = 0;  	
    TRISEbits.TRISE1 = 0;
    
    PORTA = 0b11111111;
    LATA = LATB = LATD = TRISA = TRISD = 0; // Todos como saída
	TRISB = 0x0F;			// RB0 a RB3 Entrada e RB4 a RB7 como saída
	CMCON = 0x07;			// desliga pinos analógicos do comparador
	ADCON1 = 0x0F;			// desliga pinos analógicos do ADC
    
}

void lerTECLAS(int *TECLA2)
{
        // PRIMEIRA COLUNA DO TECLADO
		PORTAbits.RA3 = 0; //habilita primeira coluna  do teclado
		tecla.sete = PORTAbits.RA4;//tecla 7 ativada
        tecla.quatro = PORTAbits.RA5;//tecla 4 ativada
		tecla.um = PORTAbits.RA6;//tecla 1 ativada
        tecla.on_clear = PORTAbits.RA7;//tecla on_clear ativada
		if (tecla.sete == 0){ // Tecla 7 foi acionada
            *TECLA2= 1;
		}else if (tecla.quatro == 0){ // Tecla 4 foi acionada
            *TECLA2= 2;
		}else if (tecla.um == 0){ // Tecla 1 foi acionada
            *TECLA2= 3;
		}else if (tecla.on_clear == 0){ // Tecla on_clear foi acionada
            *TECLA2= 4;
		}
		PORTAbits.RA3 = 1; //desabilita primeira coluna do teclado

        //--------------------------------------------------------------------------
		// SEGUNDA COLUNA DO TECLADO
		PORTAbits.RA2 = 0; //habilita segunda coluna do teclado
		
		tecla.oito = PORTAbits.RA4;//habilita tecla 8
        tecla.cinco = PORTAbits.RA5;//habilita tecla 5
		tecla.dois = PORTAbits.RA6;//habilita tecla 2
        tecla.zero = PORTAbits.RA7;//habilita tecla 0
		
		if (tecla.oito == 0){ // Tecla 8 foi acionada
            *TECLA2= 5;
		}else if (tecla.cinco == 0){ // Tecla 5 foi acionada
            *TECLA2= 6;
		}else if (tecla.dois == 0){ // Tecla 2 foi acionada
            *TECLA2= 7;
		}else if (tecla.zero == 0){ // Tecla 0 foi acionada
            *TECLA2= 8;
		}
		PORTAbits.RA2 = 1; //desabilita segunda coluna do teclado
		
		//------------------------------------------------------------------------
		// TERCEIRA COLUNA DO TECLADO
		PORTAbits.RA1 = 0; //habilita terceira coluna do teclado
		
		tecla.nove = PORTAbits.RA4;//habilita tecla 9
        tecla.seis = PORTAbits.RA5;//habilita tecla 6
		tecla.tres = PORTAbits.RA6;//habilita tecla 3
        tecla.igual = PORTAbits.RA7;//habilita tecla =
		
		if (tecla.nove == 0){ // Tecla 9 foi acionada
            *TECLA2=9;
		}else if (tecla.seis == 0){ // Tecla 6 foi acionada
            *TECLA2= 10;
		}else if (tecla.tres == 0){ // Tecla 3 foi acionada
            *TECLA2= 11;
		}else if (tecla.igual == 0){ // Tecla = foi acionada
            *TECLA2= 12;
		}
		PORTAbits.RA1 = 1; //desabilita segunda coluna do teclado
        
        //------------------------------------------------------------------------
		// QUARTA COLUNA DO TECLADO
		PORTAbits.RA0 = 0; //habilita quarta coluna do teclado
		
		tecla.divisao = PORTAbits.RA4;//habilita tecla /
        tecla.multi = PORTAbits.RA5;//habilita tecla *
		tecla.menos = PORTAbits.RA6;//habilita tecla -
        tecla.mais = PORTAbits.RA7;//habilita tecla +
		
		if (tecla.divisao == 0){ // Tecla / foi acionada
            *TECLA2=13;
		}else if (tecla.multi == 0){ // Tecla * foi acionada
            *TECLA2= 14;
		}else if (tecla.menos == 0){ // Tecla - foi acionada
            *TECLA2= 15;
		}else if (tecla.mais == 0){ // Tecla + foi acionada
            *TECLA2= 16;
		}
		PORTAbits.RA0 = 1; //desabilita quarta coluna do teclado
        
        //------------------------------------------------------------------------
	
	
        
}


int leitor_de_operacao()
{
    int resultado = 0;
    if(PORTBbits.RB0 == 0 && PORTAbits.RA5 == 0)//inversao de sinal
    {
        resultado = 1;
    }
    if(PORTAbits.RA7 == 0 && PORTAbits.RA5 == 0)//porcentagem
    {
        resultado = 2;
    }
    if(PORTAbits.RA6 == 0 && PORTAbits.RA5 == 0)//raiz quadrada
    {
        resultado = 3;
    }
    if(PORTAbits.RA1 == 0 && PORTBbits.RB1 == 0)//multiplicacao
    {
        resultado = 4;
    }
    if(PORTAbits.RA6 == 0 && PORTAbits.RA1 == 0)//subtracao
    {
        resultado = 5;
    }
    if(PORTBbits.RB0 == 0 && PORTAbits.RA1 == 0)//subtracao
    {
        resultado = 6;
    }
    if(PORTBbits.RB1 == 0 && PORTAbits.RA0 == 0)//divisao
    {
        resultado = 7;
    }
    if(PORTBbits.RB0 == 0 && PORTAbits.RA0 == 0)//potencia
    {
        resultado = 8;
    }
    if(PORTAbits.RA0 == 0 && PORTAbits.RA7 == 0)//pi
    {
        resultado = 9;
    }
    if(PORTAbits.RA0 == 0 && PORTAbits.RA6 == 0)//fatorial
    {
        resultado = 10;
    }
    return resultado;
}
// Inicialização do microcontrolador
void main()
{
    int indicador_de_operacao = 0;
    int TECLA2 = 0;
    char *mensagem = "minhacalculadora";
    char *mensagem2 = "you are great";
    //INTCON= 0B00000000;    // DESABILITA AS INTERRUPÇÕES
    //INTCON2= 0B00000000;   // PULL-UPs INTERNOS DO PORTB DESABILITADOS
    RCON= 0B10000000;      // ATIVA SISTEMA DE PRIORIDADE DAS INTERRUPÇÕES
    ADCON1= 0B11111111;    // CONFIGURA PORTA E PORTB COMO I/O DIGITAL
    do
    {
        definirPORTAS();
        lerTECLAS(&TECLA2);
        switch(TECLA2)
        {
            case 1:
            {
                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
                LCD_write_char('\f');       	// apaga os dados do display
                LCD_pos_xy(0,0);    			// posiciona o cursor na primeira coluna e primeira linha
                LCD_write_string_rom(mensagem); // escreve string no display
                LCD_pos_xy(0,1);    			// posiciona o cursor na primeira coluna e primeira linha
                LCD_write_string_rom(mensagem2);// escreve string no display
                __delay_ms(100);
                
            }
//            case 2:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 3:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 4:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 5:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 6:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 7:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 8:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 9:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 10:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 11:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 12:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//                
//            }
//            case 13:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 14:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 15:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
//            case 16:
//            {
//                LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
//                LCD_write_char('\f');	// apaga os dados do display
//                LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem); // escreve string no display
//                LCD_pos_xy(0,1); 			// posiciona o cursor na primeira coluna e primeira linha
//                LCD_write_string_rom(mensagem2);// escreve string no display
//                __delay_ms(100);
//            }
            
        }
        //LCD_write_string_rom(linha);
        
//        while(contador_de_teclas < 10 || indicador_de_operacao != 0)
//        {
//            lerTECLAS(&TECLAS2);
//        }
        indicador_de_operacao = leitor_de_operacao();
        switch(indicador_de_operacao)
        {
            case 1://inversor de sinal
            {
                //codigo para mostrar o resultado no LCD
            }
            case 8://exibir pi
            {
                
            }
        }
        
    }while(1);
     
    
}
        