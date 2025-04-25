/*
    Cabeçalho:

    Giovanni de Lucca Gomieri, 248662
    José Luiz Pinto Signoretti Garcia, 248896
    Samuel de Moraes Delgado, 248729
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para ler os dados de entrada (quantidade de pontos e os pares (x, y))
void lerDados(int *n, double **x, double **y)
{
    printf("Digite o número de pontos: ");
    scanf("%d", n); // Lê o número de pontos e armazena no endereço apontado por n

    // Aloca dinamicamente memória para os vetores x e y
    *x = (double *)malloc(*n * sizeof(double));
    *y = (double *)malloc(*n * sizeof(double));

    // Lê os pares (x, y)
    printf("Digite os pares (x, y):\n");
    for (int i = 0; i < *n; i++)
    {
        printf("Ponto %d:\n", i + 1);
        printf("x: ");
        scanf("%lf", (*x + i)); // Acessa x[i] via ponteiro
        printf("y: ");
        scanf("%lf", (*y + i)); // Acessa y[i] via ponteiro
    }
}

// Constrói o sistema de equações normais para o ajuste polinomial
void construirSistema(int grau, int n, double *x, double *y, double **A, double *b)
{
    for (int i = 0; i <= grau; i++)
    {
        for (int j = 0; j <= grau; j++)
        {
            *(*(A + i) + j) = 0; // Inicializa A[i][j] com 0

            for (int k = 0; k < n; k++)
            {
                // Soma dos produtos x[k]^(i+j) para preencher A[i][j]
                *(*(A + i) + j) += pow(*(x + k), i + j);
            }
        }

        *(b + i) = 0; // Inicializa b[i] com 0
        for (int k = 0; k < n; k++)
        {
            // Soma dos produtos y[k]*x[k]^i para preencher b[i]
            *(b + i) += *(y + k) * pow(*(x + k), i);
        }
    }

    // Imprime o sistema linear montado
    printf("\nSistema Linear:\n");
    for (int i = 0; i <= grau; i++)
    {
        for (int j = 0; j <= grau; j++)
        {
            printf("%.2lf\t", *(*(A + i) + j));
        }
        printf("| %.2lf\n", *(b + i));
    }
}

// Aplica o método da Eliminação de Gauss para escalonar a matriz A
void eliminacaoGauss(int grau, double **A, double *b)
{
    for (int k = 0; k <= grau; k++)
    {
        for (int i = k + 1; i <= grau; i++)
        {
            // Calcula o multiplicador m para zerar a coluna abaixo do pivô
            double m = *(*(A + i) + k) / *(*(A + k) + k);
            for (int j = k; j <= grau; j++)
            {
                // Subtrai m vezes a linha do pivô da linha atual
                *(*(A + i) + j) -= m * *(*(A + k) + j);
            }
            // Atualiza o vetor b
            *(b + i) -= m * *(b + k);
        }
    }

    // Imprime a matriz escalonada
    printf("\nSistema Escalonado:\n");
    for (int i = 0; i <= grau; i++)
    {
        for (int j = 0; j <= grau; j++)
        {
            printf("%.2lf\t", *(*(A + i) + j));
        }
        printf("| %.2lf\n", *(b + i));
    }
}

// Realiza a substituição reversa para encontrar os coeficientes do polinômio
void substituicaoReversa(int grau, double **A, double *b, double *coef)
{
    for (int i = grau; i >= 0; i--)
    {
        *(coef + i) = *(b + i); // Começa com b[i]
        for (int j = i + 1; j <= grau; j++)
        {
            // Subtrai os termos já conhecidos do lado direito
            *(coef + i) -= *(*(A + i) + j) * *(coef + j);
        }
        // Divide pelo pivô da diagonal
        *(coef + i) /= *(*(A + i) + i);
    }
}

// Imprime o polinômio ajustado com os coeficientes calculados
void imprimirPolinomio(int grau, double *coef)
{
    printf("\nPolinômio Ajustado:\nP(x) = ");
    for (int i = 0; i <= grau; i++)
    {
        if (i > 0 && *(coef + i) >= 0)
            printf("+ ");             // Adiciona '+' para coeficientes positivos
        printf("%.4lf", *(coef + i)); // Mostra coeficiente

        if (i >= 1)
            printf("x^%d ", i); // Mostra o grau
        else
            printf(" "); // Só imprime constante
    }
    printf("\n");
}

// Função principal do programa
int main()
{
    int n, grau;
    double *x, *y;

    lerDados(&n, &x, &y); // Lê os pontos

    // Garante que o grau do polinômio seja 1 ou 2
    do
    {
        printf("Escolha o grau do polinômio (1 ou 2): ");
        scanf("%d", &grau);
    } while (grau != 1 && grau != 2);

    // Aloca matriz A dinamicamente
    double **A = (double **)malloc((grau + 1) * sizeof(double *));
    for (int i = 0; i <= grau; i++)
        *(A + i) = (double *)malloc((grau + 1) * sizeof(double));

    // Aloca os vetores b e coeficientes
    double *b = (double *)malloc((grau + 1) * sizeof(double));
    double *coef = (double *)malloc((grau + 1) * sizeof(double));

    // Etapas do ajuste: construir sistema, escalonar, resolver e imprimir
    construirSistema(grau, n, x, y, A, b);
    eliminacaoGauss(grau, A, b);
    substituicaoReversa(grau, A, b, coef);
    imprimirPolinomio(grau, coef);

    // Libera toda a memória alocada
    free(x);
    free(y);
    free(b);
    free(coef);
    for (int i = 0; i <= grau; i++)
        free(*(A + i));
    free(A);

    return 0; // Fim do programa
}
