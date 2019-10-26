/*****************************************
*   File:   Calculadora.c                *
*   Author: William Torres               *
*           Arthur Brito                 *
*           Gabriel Pedro                *
*           Ruann Teixeira               *
******************************************/

#include <xc.h>//inclusão da biblioteca padrao de pic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meu_lcd16x2.c"//arquivo para usar as funções do LCD
#ifndef _XTAL_FREQ//definicao da frequencia
#define _XTAL_FREQ  4000000
#endif
struct teclas_calculadora
{
    unsigned int sete:1;
    unsigned int quatro:1;
    unsigned int um:1;
    unsigned int on_clear:1;
    unsigned int oito:1;
    unsigned int cinco:1;
    unsigned int dois:1;
    unsigned int zero:1;
    unsigned int nove:1;
    unsigned int seis:1;
    unsigned int tres:1;
    unsigned int igual:1;
    unsigned int divisao:1;
    unsigned int multi:1;
    unsigned int menos:1;
    unsigned int mais:1;
}tecla;
int contador_de_teclas = 0;
int indicador_de_operacao = 0;
int TECLA2 = 99;
int valor_x = 0;
int valor = 0;
int valor2 = 0;
int posicao_cursor = 0;
int posicao = 0;
char *mensagem1 = "1";
char *mensagem2 = "4";
char *mensagem3 = "7";
char *mensagem4 = "*";
char *mensagem5 = "2";
char *mensagem6 = "5";
char *mensagem7 = "8";
char *mensagem8 = "0";
char *mensagem9 = "3";
char *mensagem10 = "6";
char *mensagem11 = "9";
char *mensagem12 = "/";
char *mensagem13 = "+";
char *mensagem15 = "-";
char *mensagem16 = "ON/CLEAR";
char *mensagem17 = "_";
void delay_ms(int tempo){
     int time;
     for(time=tempo; time>0;time--){
         __delay_ms(1);			//Delay de 1 milisegundo
     }

}
void definirPORTAS()
{
    //Definir portas da calculadora como entrada
    TRISAbits.TRISA1 = 1;  	
	TRISAbits.TRISA2 = 1;   
	TRISAbits.TRISA3 = 1;   
	TRISAbits.TRISA4 = 1;
    //botoes
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    //portas como saída
	TRISAbits.TRISA5 = 0;   
	TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA0 = 0;
    TRISA= 0b00011110;
    TRISB= 0b00001111;
    
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
    
    PORTAbits.RA5= 1;
    PORTAbits.RA6= 1;
    PORTAbits.RA0= 1;
	CMCON = 0x07;			// desliga pinos analógicos do comparador
	ADCON1 = 0x0F;			// desliga pinos analógicos do ADC    
}

int math()
{
    int resultado = 0;
    switch(indicador_de_operacao)
    {
        case 1://MULTIPLICACAO
        {
            resultado = valor * valor2;
            break;
        }
        case 2://DIVISAO
        {
            resultado = valor / valor2;
            break;
        }
        case 3://ADICAO
        {
            resultado = valor + valor2;
            break;
        }
        case 4://SUBTRACAO
        {
            resultado = valor - valor2;
            break;
        }
    }
    return resultado;
}
void lerTECLAS()
{
        // PRIMEIRA COLUNA DO TECLADO
		PORTAbits.RA5 = 0; //habilita primeira coluna  do teclado
        
		tecla.um = PORTAbits.RA4;//tecla 7 ativada
        tecla.quatro = PORTAbits.RA3;//tecla 4 ativada
		tecla.sete = PORTAbits.RA2;//tecla 1 ativada
        tecla.multi = PORTAbits.RA1;//tecla on_clear ativada
		if (tecla.um == 0){ // Tecla 7 foi acionada
            TECLA2= 1;
            contador_de_teclas++;
		}else if (tecla.quatro == 0){ // Tecla 4 foi acionada
            TECLA2= 2;
            contador_de_teclas++;
		}else if (tecla.sete == 0){ // Tecla 1 foi acionada
            TECLA2= 3;
            contador_de_teclas++;
		}else if (tecla.multi == 0){ // Tecla on_clear foi acionada
            TECLA2= 4;
            indicador_de_operacao = 1;
		}
		PORTAbits.RA5 = 1; //desabilita primeira coluna do teclado
        //--------------------------------------------------------------------------
		// SEGUNDA COLUNA DO TECLADO
		PORTAbits.RA6= 0; //habilita segunda coluna do teclado
		
		tecla.dois = PORTAbits.RA4;//habilita tecla 8
        tecla.cinco = PORTAbits.RA3;//habilita tecla 5
		tecla.oito = PORTAbits.RA2;//habilita tecla 2
        tecla.zero = PORTAbits.RA1;//habilita tecla 0
		
		if (tecla.dois == 0){ // Tecla 8 foi acionada
            TECLA2= 5;
            contador_de_teclas++;
		}else if (tecla.cinco == 0){ // Tecla 5 foi acionada
            TECLA2= 6;
            contador_de_teclas++;
		}else if (tecla.oito == 0){ // Tecla 2 foi acionada
            TECLA2= 7;
            contador_de_teclas++;
		}else if (tecla.zero == 0){ // Tecla 0 foi acionada
            TECLA2= 8;
            contador_de_teclas++;
		}
		PORTAbits.RA6 = 1; //desabilita segunda coluna do teclado
		//------------------------------------------------------------------------
		// TERCEIRA COLUNA DO TECLADO
		PORTAbits.RA0 = 0; //habilita terceira coluna do teclado
		
		tecla.tres = PORTAbits.RA4;//habilita tecla 9
        tecla.seis = PORTAbits.RA3;//habilita tecla 6
		tecla.nove = PORTAbits.RA2;//habilita tecla 3
        tecla.divisao = PORTAbits.RA1;//habilita tecla =
		
		if (tecla.tres == 0){ // Tecla 9 foi acionada
            TECLA2=9;
            contador_de_teclas++;
		}else if (tecla.seis == 0){ // Tecla 6 foi acionada
            TECLA2= 10;
            contador_de_teclas++;
		}else if (tecla.nove == 0){ // Tecla 3 foi acionada
            TECLA2= 11;
            contador_de_teclas++;
		}else if (tecla.divisao == 0){ // Tecla = foi acionada
            TECLA2= 12;
            indicador_de_operacao = 2;
		}
		PORTAbits.RA0 = 1; //desabilita segunda coluna do teclado
        //------------------------------------------------------------------------
//		// QUARTA COLUNA DO TECLADO
			
		tecla.mais = PORTBbits.RB0;//habilita tecla /
        tecla.menos = PORTBbits.RB1;//habilita tecla *
		tecla.igual = PORTBbits.RB2;//habilita tecla -
        tecla.on_clear = PORTBbits.RB3;//habilita tecla +
		
		if (tecla.mais == 0){ // Tecla / foi acionada
            TECLA2=13;
            indicador_de_operacao = 3;
		}else if (tecla.igual == 0){ // Tecla * foi acionada
            TECLA2= 14;
		}else if (tecla.menos == 0){ // Tecla - foi acionada
            TECLA2= 15;
            indicador_de_operacao = 4;
		}else if (tecla.on_clear == 0){ // Tecla + foi acionada
            TECLA2= 16;
		}       
        //------------------------------------------------------------------------        
}

void definir_string()
{
    switch(TECLA2)
    {
        case 1:
        {
            LCD_write_string_rom(mensagem1); // escreve string no display
            delay_ms(200);
            break;
        }
        case 2:
        {
            LCD_write_string_rom(mensagem2); // escreve string no display
            delay_ms(200);
            break;
        }
        case 3:
        {
            LCD_write_string_rom(mensagem3); // escreve string no display
            delay_ms(200);
            break;
        }
        case 4:
        {
            LCD_write_string_rom(mensagem4); // escreve string no display
            delay_ms(200);
            break;
        }
        case 5:
        {
            LCD_write_string_rom(mensagem5); // escreve string no display
            delay_ms(200);
            break;
        }
        case 6:
        {
            LCD_write_string_rom(mensagem6); // escreve string no display
            delay_ms(200);
            break;
        }
        case 7:
        {
            LCD_write_string_rom(mensagem7); // escreve string no display
            delay_ms(200);
            break;
        }
        case 8:
        {
            LCD_write_string_rom(mensagem8); // escreve string no display
            delay_ms(200);
            break;
        }
        case 9:
        {
            LCD_write_string_rom(mensagem9); // escreve string no display
            delay_ms(200);
            break;
        }
        case 10:
        {
            LCD_write_string_rom(mensagem10); // escreve string no display
            delay_ms(200);
            break;
        }
        case 11:
        {
            LCD_write_string_rom(mensagem11); // escreve string no display
            delay_ms(200);
            break;
        }
        case 12:
        {
            LCD_write_string_rom(mensagem12); // escreve string no display
            delay_ms(200);
            break;
        }
        case 13:
        {
            LCD_write_string_rom(mensagem13); // escreve string no display
            delay_ms(200);
            break;
        }
        case 15:
        {
            LCD_write_string_rom(mensagem15); // escreve string no display
            delay_ms(200);
            break;
        }
        case 17:
        {
            LCD_write_string_rom(mensagem17); // escreve string no display
            delay_ms(200);
            break;
        }
        
    }
}
void definir_posicao(int posicao)
{
    switch(posicao)
    {
        case 0:
        {
            LCD_pos_xy(0,0);
            break;
        }
        case 1:
        {
            LCD_pos_xy(1,0);
            break;
        }
        case 2:
        {
            LCD_pos_xy(2,0);
            break;
        }
        case 3:
        {
            LCD_pos_xy(3,0);
            break;
        }
        case 4:
        {
            LCD_pos_xy(4,0);
            break;
        }
        case 5:
        {
            LCD_pos_xy(5,0);
            break;
        }
        case 6:
        {
            LCD_pos_xy(6,0);
            break;
        }
        case 7:
        {
            LCD_pos_xy(7,0);
            break;
        }
        case 8:
        {
            LCD_pos_xy(8,0);
            break;
        }
        case 9:
        {
            LCD_pos_xy(9,0);
            break;
        }
        case 10:
        {
            LCD_pos_xy(10,0);
            break;
        }
        case 11:
        {
            LCD_pos_xy(11,0);
            break;
        }
        case 12:
        {
            LCD_pos_xy(12,0);
            break;
        }
        case 13:
        {
            LCD_pos_xy(13,0);
            break;
        }
        case 14:
        {
            LCD_pos_xy(14,0);
            break;
        }
        case 15:
        {
            LCD_pos_xy(15,0);
            break;
        }
    }
}
// Inicialização do microcontrolador
int numero_real()
{
    int valor_real = 0;
    switch(TECLA2)
    {
        case 1:
        {
            valor_real = 1; break;
        }
        case 2:
        {
            valor_real = 4; break;
        }
        case 3:
        {
            valor_real = 7; break;
        }
        case 5:
        {
            valor_real = 2; break;
        }
        case 6:
        {
            valor_real = 5; break;
        }
        case 7:
        {
            valor_real = 8; break;
        }
        case 8:
        {
            valor_real = 0; break;
        }
        case 9:
        {
            valor_real = 3; break;
        }
        case 10:
        {
            valor_real = 6; break;
        }
        case 11:
        {
            valor_real = 9; break;
        }
    }
    valor_x = (valor_x*10 + valor_real);
    return valor_x;
}
void main()
{
    char *resultado_final = "nada ainda ;-;";
    int resultado_para_converter = 0;
    INTCON= 0B00000000;    // DESABILITA AS INTERRUPÇÕES
    INTCON2= 0B00000000;   // PULL-UPs INTERNOS DO PORTB DESABILITADOS
    RCON= 0B10000000;      // ATIVA SISTEMA DE PRIORIDADE DAS INTERRUPÇÕES
    ADCON1= 0B11111111;    // CONFIGURA PORTA E PORTB COMO I/O DIGITAL
    definirPORTAS();
    do
    {
        TECLA2 = 16;
        if(TECLA2 == 16)
        {
            LCD_init(DISPLAY_8X5|_2_LINES, DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
            LCD_pos_xy(0,0); 			// posiciona o cursor na primeira coluna e primeira linha
            LCD_write_string_rom(mensagem17); // escreve string no display
            LCD_pos_xy(15,1); 			// posiciona o cursor na primeira coluna e primeira linha
            LCD_write_string_rom(mensagem8); // escreve string no display
            delay_ms(1000);
        }
        TECLA2 = 99;
        posicao_cursor = 0;
        while(posicao_cursor < 16)
        {
            posicao = posicao_cursor;//inicialmente posicao comeca com 0
            posicao_cursor++;//incrementacao de posicao_cursor
            while(1)
            {
                lerTECLAS();
                if(TECLA2 != 99)
                    break;
            }
            definir_posicao(posicao);//posicao no LCD do numero que foi digitado.
            definir_string();//define qual caractere vai mostrar no LCD
            if(TECLA2 != 4 || TECLA2 != 12 || TECLA2 != 13 || TECLA2 != 15)
                valor = numero_real();
            else    valor2 = numero_real();
            if(TECLA2 == 14)
            {
                /*mostrar o resultado final na linha 1*/
                /*alguma variavel vai receber o retorno da funcao math*/
                /*essa variavel ira ter seu valor convertido em char* */
                /*esse novo valor char* ira para alguma variavel*/
                /*essa nova variavel ser o argumento da funcao LCD_write_string_rom */
                resultado_para_converter = math();
                resultado_final = resultado_para_converter + 0x30;
                LCD_pos_xy(0,1);
                LCD_write_string_rom(resultado_final);
                TECLA2 = 16;
                delay_ms(2000);
            }
            if(TECLA2 == 16)
            {
                /*limpar a tela e zera as variaveis*/
                TECLA2 = 99;
                valor = 0;
                valor2 = 0;
                LCD_write_char('\f');	// apaga os dados do display
                LCD_pos_xy(0,0);
                posicao_cursor = 0;
            }
            TECLA2 = 17;
            definir_string();//define qual caractere vai mostrar no LCD
            TECLA2 = 99;
        }
    }while(1);
     
    
}

        