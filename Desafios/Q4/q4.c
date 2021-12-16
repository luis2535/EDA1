#include <stdlib.h>
#include <stdio.h>
#include "q4.h"

Fibonacci *inicializa()
{
    Fibonacci *p;
    p = NULL;
    return p;
}
Fibonacci *cria(int valor)
{
    Fibonacci *p;
    p = (Fibonacci *)malloc(sizeof(Fibonacci));
    p->dado = valor;
    p->prox = NULL;
    return p;
}
Fibonacci *criaLSE(Fibonacci *lista, int valor)
{
    Fibonacci *p;
    p = lista;
    if (p == NULL)
    {
        p = cria(valor);
        return p;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = cria(valor);
    return lista;
}
void imprime_lista(Fibonacci *lista)
{
    Fibonacci *p;
    p = lista;
    printf("Lista: \n");
    while (p != NULL)
    {
        printf("Valor: %d\n", p->dado);
        p = p->prox;
    }
}
int ehprimo(int n)
{
    int div = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            div++;
        }
    }
    if (div == 2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}