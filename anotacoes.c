/*

    Conteúdo Programático:

    * Método para cálculo de raízes: Dicotomia ou Bissecção.
    * Método de Interpolação: Polinômio de Lagrange.
    * Métodos para Resolução de Sistemas Lineares: Eliminação de Gauss.
    * Método para ajuste de Curvas: Método dos Quadrados Mínimos.
    * Método de Integração Numérica: Regra dos Trápezios.

    Provas:

    AC1: 02/04
    AC2: Tarefa 1 - 09/04 | Prova - 14/05 | Tarefa 2 - 21/05
    AG: 20/05
    AF: 11/06
    AS: 25/06

    
    * Métodos Interativos para Obtenção de Raízes:
    
    - Fase I

        A ideia central desses métodos é partir de uma aproximação inicial para a raiz e em
        seguida refinar essa aproximação através de um processo iterativo.

        Ex.: 

        F(A) = F(1) = -
        F(B) = F(2) = +

        F(A) * F(B) < 0 --> Existe um zero nesse intervalo de função.

    - Fase II

        Refinamento:

        M = A+B/2 --> Ponto médio do intervalo achado.

        Ex.: M = 1 + 2/2 = 1,5

        Depois... F(A) * F(M) < 0 --> O 0 está no intervalo entre [A;M],
        e então o M vira seu novo B.

        O mesmo vai valer pelo contrário, se F(M) * F(B) < 0 --> O 0 está no 
        intervalo entre [M; B], e então o M vira seu novo A.

        Reaplique esse processo até:

            1. |Bk - Ak| <= Erro Estipulado
            2. | F(m) | <= Erro Estipulado
            3. k >= (log(Bo-Ao) - log(erro)) / log(2) --> Número de passos que preciso fazer 
                para chegar naquela função. Caso dê um número quebrado, SEMPRE arredonde para
                cima.

    Método da Dictomia:
        
        São 3 requisitos para aplicar o método numérico da Dictomia:

        1. Equação - A qual se deseja extrair a raiz.
        2. Intervalo - Valor máximo onde a raiz da equação se encontra.
        3. Precisão - Erro tolerável.


    Exercício:

    Função = f(x) = 2x² - 3
    Intervalo = [-1.5, -1]
    Precisão = 0.01


    1°Passo: 

    F(-1.5) * F(-1) < 0
    1.5 * (-1) < 0
    -1.5 < 0 --> Existe um 0 nesse intervalo de função.

    2° Passo:

    k>= (log(-1 - (-1.5)) - log(0.01))/log(2)
    k>= 5,64 --> 6

    3° Passo: 

    a = -1.5 | b = -1 | m = -1.25 | f(a) = 1.5 | f(b) = -1 | f(m) = 0.125 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = -1.25 | b = -1 | m = -1.125 | f(a) = 0.125 | f(b) = -1 | f(m) = -0.4688 |f(a) * f(m) = - | f(m) * f(b) = + |
    a = -1.25 | b = -1.125 | m = -1.1875 | f(a) = 0.125 | f(b) = -0.4688 | f(m) = -0.1796875 | f(a) * f(m) = - | f(m) * f(b) = + |
    a = -1.25 | b = -1.1875 | m = -1.21875 | f(a) = 0.125 | f(b)  = -0.1796875 | f(m) = -0.029296875 | f(a) * f(m) = + | f(m) * f(b) = - |
    a =  -1.21875 | b = -1.1875 | m = -1.20315 | f(a) = -0.029296875 | f(b) = -0.1796575 | f(m) = ...


    Outros Exercícios:

    1)    
        f(x) = x^3 - 20 
        I = [2,3]
        Erro = 0,01

    F(A) * F(B) < 0
    F(2) * F(3) < 0
    -12 * 7 < 0
    -84 < 0 --> Existe um zero de função.

    k >= (log(3-2) - log(0,01))/log(2)
    k >= 6,64
    k = 7

    a = 2 | b = 3 | m = 2.5 | f(a) = -12 | f(b) = 7 | f(m) = -4.3750 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = 2.5 | b = 3 | m = 2.75 | f(a) = -4.3750 | f(b) = 7 | f(m) = 0,7968 | f(a) * f(m) = - | f(m) * f(b) = + |
    a = 2.5000 | b = 2.7500 | m = 2,6250 | f(a) = -4.3750 | f(b) = 0.7968 | f(m) = -1.9121 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = 2.6250 | b = 2.7500 | m = 2.6875 | f(a) = -1.9121 | f(b) = 0.7968 | f(m) = -0.5891 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = 2.6875 | b = 2.7500 | m = 2.7187 | f(a) = -0.5891 | f(b) = 0.7968 | f(m) = +0.0959 | f(a) * f(m) = - | f(m) * f(b) = + |
    a = 2.6875 | b = 2.7187 | m = 2.7031 | f(a) = -0.5891 | f(b) = 0.0959 | f(m) = -0.2491 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = 2.7031 | b = 2.7187 | m = 2,7109 | f(a) = -0.2491 | f(b) = 0.0959 | f(m) = -0.0776 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = 2.7109 | b = 2.7187 | m = 2.7148 | f(a) = -0.0776 | f(b) = 0.0959 | f(m) = +0.0084 | f(a) * f(m) = - | f(m) * f(b) = + |

    P = 2.7148 é o ponto zero da função

    2) 
        f(x) = x^3 - 4x^2 - 10
        I = [1, 2]
        Erro = 0,001

        f(A) * f(B) < 0
        f(1) * f(2) < 0
        -13 * -18 < 0
        234 < 0

        Não dá pra descobrir...

    
    3)
        f(x) = e^x + x
        I = [-1, 0]
        Erro = 0,05

    f(a) * f(b) < 0
    f(-1) * f(0) < 0
    -0.6321 * 1 < 0
    -0.6321 < 0

    k >= (log(1) - log(0.05))/log(2)
    k >= 4.32
    k = 5

    a = -1.0000 | b = +0.0000 | m = -0.5000 | f(a) = -0.6321 | f(b) = +1.0000 | f(m) = +1.1065 | f(a) * f(m) = - | f(m) * f(b) = + |
    a = -1.0000 | b = -0.5000 | m = -0.7500 | f(a) = -0.6321 | f(b) = +1.1065 | f(m) = +0.4723 | f(a) * f(m) = - | f(m) * f(b) = + |
    a = -1.0000 | b = -0.7500 | m = -0.8750 | f(a) = -0.6231 | f(b) = +0.4723 | f(m) = +0.4168 | f(a) * f(m) = + | f(m) * f(b) = - |
    a = -0.8750 | b = -0.7500 | m = -0.8125 | f(a) = +0.4168 | f(b) = +0.4723 | f(m) = 

*/
