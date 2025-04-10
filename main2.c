/*
    Giovanni de Lucca Gigomieri
    José Luiz Pinto Signoretti Garcia, 248896
    Samuel de Moraes Delgado, 248729
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para receber os dados de entrada
void receberDados(int pontos, float *valoresX, float *valoresFX)
{
    for (int i = 0; i < pontos; i++)
    {
        printf("Digite o valor de x[%d]: ", i);
        scanf("%f", (valoresX + i)); //Recebendo dados dos pontos X
        printf("Digite o valor de f(x[%d]): ", i);
        scanf("%f", (valoresFX + i)); // Recebendo dados dos F(x)
    }
}

// Função para calcular Lk(x)
float calcularLk(int k, int pontos, float x, float *valoresX)
{
    float resultado = 1.0;
    for (int i = 0; i < pontos; i++)
    {
        if (i != k)
        {
            resultado *= (x - *(valoresX + i)) / (*(valoresX + k) - *(valoresX + i)); //Aplicando o Polimônio de Lagrange (Fórmula do Produdório que i != k. Portanto L(x) = (x-xi)/(xk - xi)
        }
    }
    return resultado;
}

// Função para calcular P(x) usando interpolação de Lagrange
float interpolarLagrange(int pontos, float x, float *valoresX, float *valoresFX)
{
    float resultado = 0.0;
    for (int k = 0; k < pontos; k++)
    {
        float Lk = calcularLk(k, pontos, x, valoresX); //Calcula o Polimônio de Lagrange
        printf("L%d(%.2f) = %.4f\n", k, x, Lk);
        resultado += *(valoresFX + k) * Lk; // Faz a interpolação do Lagrange --> L(0)*F(x0) + L(1)*F(x1)...L(n)*F(xn)
    }
    return resultado;
}

int main()
{
    int grau, pontos;
    float *valoresX = NULL, *valoresFX = NULL;
    float valorCalcular, resultado;
    char resp;

    //----------------------------------------------------

    printf("Digite o grau da funcao que deseja obter: ");
    scanf("%d", &grau); //Grau da Função
    pontos = grau + 1; //Pontos da Função --> 1°Grau = 2 Pontos | 2° Grau = 3 Pontos | 3° Grau = 4 Pontos | ...

    //----------------------------------------------------

    // Alocação dinâmica
    valoresX = (float *)malloc(pontos * sizeof(float));
    valoresFX = (float *)malloc(pontos * sizeof(float));

    if (valoresX == NULL || valoresFX == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    //----------------------------------------------------

    // Recebendo os dados
    receberDados(pontos, valoresX, valoresFX);

    do
    {
        printf("\nDigite o valor de x que deseja calcular f(x): ");
        scanf("%f", &valorCalcular); // Pegando o valor da Funçao que deseja calcular

        resultado = interpolarLagrange(pontos, valorCalcular, valoresX, valoresFX);

        printf("f(%.2f) = %.4f\n", valorCalcular, resultado); // Printando o resultado final

        printf("\nDeseja calcular outro valor (s/n)? "); 
        fflush(stdin);
        scanf(" %c", &resp); // Recebendo a resposta

    } while (resp == 's' || resp == 'S');

   //----------------------------------------------------

    // Liberação de memória
    free(valoresX);
    free(valoresFX);

    system("pause");
    return 0;
}
