                                       Calculadora Digital com Teclado Matricial e LCD 16x2
                                       
                                       
Objetivos: Criação de software e implementação no hardware (em simulação) de uma calculadora digital com teclado matricial e display LCD.
A calculadora realizará somente as operações básicas, que são: Adição (+), Subtração (-), Multiplicação (*) e Divisão (/).

Lista de componentes necessários:
              
    1 Microcontrolador PIC18F4520
    4 Botões (push-button)
    4 Resistores 10kΩ
    4 Resistores 1kΩ
    1 Potenciômetro 1kΩ
    1 Teclado Matricial 3x4
    1 Display LCD 16x2 (LM016L)



Teremos algumas definições, que são:
  Quando o botão estiver pressionado, ficará com uma indicação no LED da cor AZUl, e terá valor igual a 1 (um).
  Quando o botão estiver aberto (não pressionado), ficará com uma indicação no LED da cor VERMELHA, e terá valor igual a 0 (zero).

Na idealização do projeto, a calculadora iniciava-se desligada, e para ser ligada, era necessário a ativação do botão ON/CLEAR. 7
Esta funcionalidade foi descartada, mas pode ser revista.





Abaixo teremos algumas definições que corresponderá entre um valor inteiro e a qual tecla ela pertence.

    um = 1                 dois = 5      três = 9       mais = 13
    quatro = 2             cinco = 6     seis = 10      igual = 14
    sete = 3               oito = 7      nove = 11      menos = 15
    multiplicação = 4      zero = 8      divisão = 12   ON/CLEAR = 16
