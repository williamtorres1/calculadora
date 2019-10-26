Calculadora digital com teclado e LCD.

Lista de componentes:
1 - PIC18F4520
2 - KEYPAD-CALCULATOR
3 - WIRES
4 - 10 RESITORS
5 - POWER
6 - LCD ALFANUMÉRICO (LM016L)


O projeto apresentará uma Calculadora digital, que terão as seguintes funções matemáticas:
1 - Adição(+)
2 - Subtração(-)
3 - Multiplicação(*)
4 - Divisão(/)
5 - Porcentagem(%)
6 - Raiz Quadrada(v)
7 - Potência(MRC)
8 - pi(M-)
9 - Fatorial(M+)
10 - inversão de sinal(+/-)

Substituiremos as teclas MRC, M- e M+ para outras operações, porque sentimos essa necessidade de possuir estas funções em uma calculadora digital.

BOTÃO PRESSIONADO = AZUL = 1
BOTÃO ABERTO = VERMELHO = 0

Ao iniciar a simulação a calculadora estará desligada. Ao apertaro botão “on/c” irá ligar a calculadora (mostrando uma mensagem no LCD. Ex: “ESTÁ LIGADA”.).

A calculadora receberá 9 números ou 8 numeros e uma vírgula. Após digitar tais números, o usuário deverá apertar o botão da operação que deseja realizar.
Ex: 78597.45 + 12.

LCD:
    1. //adicionar o codigo fonte no projeto (meu_lcd16x2.c)
    2. //iniciar o LCD
    3. //testar com um texto simples o funcionamento
TECLADO:
    1. exibir a tecla pressionada no LCD
    2. atribuir a uma variavel o valor digitado no teclado.
    3. Exibir no LCD o valor da variável.

on_clear = 1
Sete = 5
Oito = 9
Nove = 13
Multi = 17
Divisao = 20
Inversor = 2
Quatro = 6
cinco = 10
Seis = 14
Menos = 18
Potenci = 21
Percent = 3
Um = 7
Dois = 11
Tres = 15
Mais = 19
Pi = 22
Raiz = 4
Zero = 8
Ponto = 12
Igual = 16

Fatori = 23


O teclado de calculadora 4x6 depende da biblioteca keypad.h, para arduinos. Então será substituído pelo teclado 4x4 de matemática com as operações básicas.

Sete = 1
Oito = 5
Nove = 9
Divisao = 13
Quatro = 2
Cinco = 6
Seis = 10
Multi = 14
Um = 3
Dois = 7
Tres = 11
Menos = 15
on_clear = 4
Zero = 8
Igual = 12
Mais = 16

