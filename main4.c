/*
    Cabeçalho:

    Giovanni de Lucca Gomieri, 248662
    José Luiz Pinto Signoretti Garcia, 248896
    Samuel de Moraes Delgado, 248729
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Protótipos
float calcularFuncao(float x, int grau, float *coeficientes);
void receberDados(int *grau, float **coef, float *a, float *b, int *n);
float integrarTrapz(float a, float b, int n, int grau, float *coef);

int main()
{
    int grau, n;
    float *coeficientes;
    float a, b;
    char repetir;

    do
    {
        // Entrada dos dados
        receberDados(&grau, &coeficientes, &a, &b, &n);

        // Cálculo da integral
        float resultado = integrarTrapz(a, b, n, grau, coeficientes);

        // Resultado
        printf("\nResultado da integral no intervalo [%.2f, %.2f]: %.5f\n", a, b, resultado);

        // Libera a memória
        free(coeficientes);

        // Pergunta se o usuário quer repetir
        printf("\nDeseja calcular outra integral? (s/n): ");
        scanf(" %c", &repetir);

    } while (repetir == 's' || repetir == 'S');

    return 0;
}

// Função que calcula o valor do polinômio em um ponto x
float calcularFuncao(float x, int grau, float *coeficientes)
{
    float resultado = 0;
    for (int i = 0; i <= grau; i++)
    {
        resultado += *(coeficientes + i) * pow(x, i);
    }
    return resultado;
}

// Função que recebe os dados do usuário
void receberDados(int *grau, float **coef, float *a, float *b, int *n)
{
    printf("Informe o grau da funcao (2 a 10): ");
    scanf("%d", grau);

    *coef = (float *)malloc((*grau + 1) * sizeof(float));
    if (*coef == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i <= *grau; i++)
    {
        printf("Informe o coeficiente de x^%d: ", i);
        scanf("%f", (*coef+i));
    }

    printf("Informe o valor inicial do intervalo (a): ");
    scanf("%f", a);
    printf("Informe o valor final do intervalo (b): ");
    scanf("%f", b);
    printf("Informe o numero de subdivisoes (N): ");
    scanf("%d", n);
}

// Função que realiza a integração usando a Regra dos Trapézios
float integrarTrapz(float a, float b, int n, int grau, float *coef)
{
    float h = (b - a) / n;
    float soma = calcularFuncao(a, grau, coef);

    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        soma += 2 * calcularFuncao(x, grau, coef);
    }

    soma += calcularFuncao(b, grau, coef);
    return (h / 2.0) * soma;
}
