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
    a =  -1.21875 | b = -1.1875 | m = -1.20315 | f(a) = -0.029296875 | f(b) = -0.1796575 | f(m) = 
*/
