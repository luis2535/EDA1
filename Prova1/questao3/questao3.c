#include "questao3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

polinomio *inicializa()
{
    polinomio *p;
    p = NULL;
    return p;
}
polinomio *cria_nodo(int coeficiente)
{
    polinomio *novo;
    novo = (polinomio *)malloc(sizeof(polinomio));
    novo->coeficiente = coeficiente;
    novo->prox = NULL;
    return (novo);
}
polinomio *insere_fim(polinomio *l, polinomio *novo)
{
    polinomio *p;
    p = l;
    if (l == NULL)
    {
        return (novo);
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return (l);
}
int conta_nos(polinomio *l)
{
    polinomio *p;
    p = l;
    int cont = 0;
    if (l == NULL)
    {
        return (-1);
    }
    else
    {
        while (p != NULL)
        {
            cont++;
            p = p->prox;
        }
        return (cont);
    }
}
void imprime_lista(polinomio *l)
{
    polinomio *p;
    p = l;
    int exp; // variavel recebera o numero de posicoes do polinomio para impressao de seu expoente
    exp = conta_nos(l);
    while (p != NULL)
    {
        printf(" %dx^%d + ", p->coeficiente, exp - 1);
        p = p->prox;
        exp--;
    }
    printf("0\n");
}
float calcular(polinomio *l, float x)
{
    polinomio *p;
    p = l;
    int exp; // variavel recebera o numero de posicoes do polinomio para impressao de seu expoente
    exp = conta_nos(l);
    float soma = 0; // recebera o valor de cada coeficiente apos operacao;
    while (p != NULL)
    {
        exp--;
        soma += p->coeficiente * (pow(x, exp));
        p = p->prox;
    }
    return soma;
}