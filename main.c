#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*
Dicas:
        Potencia: pow(base, expoente)
        Arredondar para cima: ceil(valor)
        Modulo/ValorAbsoluto: fabs(valor)
*/


//Prototipo das funcoes
//Criar funcao para calcular a DICOTOMIA
float CalculaValorK(float a, float b, float erro);
float funcaoX(float ponto);
void ImprimirCabecalhoTabela();
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB);
float acharPontoMedio(float a, float b);

float *multi = NULL;
int grau;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, tamanho =7;
    multi = (float *)malloc(tamanho * sizeof(float));

    printf("Informe o grau da funcao (2 a 6): ");
    scanf("%i", &grau);

    for(i=grau; i>=0; i--, multi++)
    {
        printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+(grau-i));
        scanf("%f", multi);
    }

    printf("A funcao recebida foi: ");

    for(i=grau; i>=0; i--)
    {
        if(i==0)
            printf("%.2f = 0", *(multi-i-1));
        else
            printf("%.2fx^%i + ", *(multi-i-1), i);
    }

    printf("\n\n");
    system("pause");
    printf("\n\n");

    float a, b, erro;

    printf("\nDigite o intervalo A:B [A]: ");
    scanf("%f", &a);

    printf("\nDigite o intervalo A:B [B]: ");
    scanf("%f", &b);

    printf("\nDigite o erro: ");
    scanf("%f", &erro);


    float funca = funcaoX(a);
    float funcb = funcaoX(b);

    printf("\nResultado Função [A]: %f", funcaoX(a));
    printf("\nResultado Função [B]: %f", funcaoX(b));
    system("pause");

    ImprimirCabecalhoTabela();
    if((funca*funcb) < 0)
    {
        int I = 1, K;

        K = CalculaValorK(a, b, erro);
        char fAfm, fBfm;
        float m = acharPontoMedio(a,b);
        float funcm = funcaoX(m);

        if((funca * funcm)<0)
        {
            fBfm = '-';
            fAfm = '+';
        }
        else
        {
            fBfm = '+';
            fAfm = '-';
        }

        ImprimirTabela(I, a, b, m, funca, funcb, funcm, fAfm, fBfm);

        do
        {
            float m = acharPontoMedio(a,b);
            float funcm = funcaoX(m);

            if((funca * funcm)<0)
            {
                b = m;
                funcb = funcm;
                fBfm = '-';
                fAfm = '+';
            }
            else
            {
                a = m;
                funca = funcm;
                fBfm = '+';
                fAfm = '-';
            }
            I++;
            ImprimirTabela(I, a, b, m, funca, funcb, funcm, fAfm, fBfm);

        }while(K>=I);
    }

    else
    {
        printf("\nDicotomia não é válida para o intervalo informado.\n");
    }

    system("pause");
    free (multi);
    return 0;
}

//Realiza o calculo do K (numero de passo)
float CalculaValorK(float a, float b, float erro)
{
    float fValorK;

    fValorK = (log10(b-a) - log10(erro))/(log10(2));
    
    return ceil(fValorK);
}

//Funcao que realiza o calculo em em determinado ponto
float funcaoX(float ponto)
{
    int i;
    float resultado;
    resultado = 0;

    for(i=0; i<=grau; i++)
    {
        resultado = resultado + *(multi-i-1)*pow(ponto, i);
    }

    return resultado;
}

//Imprimindo o cabecalho
void ImprimirCabecalhoTabela()
{
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");
}

//Imprimindo a tabela com os valores
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB)
{
	printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
}

float acharPontoMedio(float a, float b)
{
    return (a+b)/2;
}
