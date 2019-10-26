                                       Calculadora Digital com Teclado Matricial e LCD 16x2
                                       
                                       
Objetivos: Criação de software e implementação no hardware (em simulação) de uma calculadora digital com teclado matricial e display LCD.
A calculadora realizará somente as operações básicas, que são: Adição (+), Subtração (-), Multiplicação (*) e Divisão (/).

Lista de componentes necessários:

1 Microcontrolador PICF4520

4 Botões (push-button)

4 Resistores 10k

4 Resistores 1k

1 Potenciômetro 1k

1 Teclado Matricial 3x4

1 Display LCD 16x2 (LM016L)



Teremos algumas definições, que são:
  Quando o botão estiver pressionado, ficará com uma indicação no LED da cor AZUl, e terá valor igual a 1 (um).
  Quando o botão estiver aberto (não pressionado), ficará com uma indicação no LED da cor VERMELHA, e terá valor igual a 0 (zero).

Na idealização do projeto, a calculadora iniciava-se desligada, e para ser ligada, era necessário a ativação do botão ON/CLEAR. 7
Esta funcionalidade foi descartada, mas pode ser revista.





Abaixo teremos algumas definições que corresponderá entre um valor inteiro e a qual tecla ela pertence.
