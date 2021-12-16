#include "q8.h"
#include <stdio.h>
#include <stdlib.h>

polinomio *inicializa()
{
    polinomio *p;
    p = NULL;
    return p;
}
polinomio *cria_nodo(int coeficiente, int expoente)
{
    polinomio *novo;
    novo = (polinomio *)malloc(sizeof(polinomio));
    novo->coeficiente = coeficiente;
    novo->expoente = expoente;
    novo->prox = NULL;
    return (novo);
}
polinomio *insere_ordenado(polinomio *lista, polinomio *novo)
{
    polinomio *p;
    polinomio *a;
    a = NULL;
    p = lista;
    if (p == NULL)
    {
        return novo;
    }
    while (p != NULL && p->expoente > novo->expoente)
    {
        a = p;
        p = p->prox;
    }
    if (a == NULL)
    {
        novo->prox = lista;
        return novo;
    }
    if (p == NULL)
    {
        a->prox = novo;
    }
    else
    {
        novo->prox = p;
        a->prox = novo;
    }
    return lista;
}
polinomio *concatena(polinomio *lista1, polinomio *lista2)
{
    polinomio *p;
    p = lista1;
    if (p == NULL)
    {
        return lista2;
    }
    if (lista2 == NULL)
    {
        return lista1;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = lista2;
    return lista1;
}
polinomio *somaPolinomio(polinomio *lista1, polinomio *lista2)
{
    polinomio *p;
    polinomio *z;
    p = lista1;
    z = lista2;
    polinomio *resultante;
    polinomio *novo;
    novo = NULL;
    resultante = NULL;
    if (p == NULL)
    {
        printf("lista1 vazia.\n");
        return z;
    }
    if (z == NULL)
    {
        printf("Lista vazia.\n");
        return p;
    }
    while (p != NULL && z != NULL)
    {
        if (p->expoente == z->expoente)
        {
            novo = (polinomio *)malloc(sizeof(polinomio));
            novo->coeficiente = p->coeficiente + z->coeficiente;
            novo->expoente = p->expoente;
            novo->prox = NULL;
            resultante = concatena(resultante, novo);
            p = p->prox;
            z = z->prox;
        }
        else if (p->expoente > z->expoente)
        {
            novo = (polinomio *)malloc(sizeof(polinomio));
            novo->coeficiente = p->coeficiente;
            novo->expoente = p->expoente;
            novo->prox = NULL;
            resultante = concatena(resultante, novo);
            p = p->prox;
        }
        else if (z->expoente > p->expoente)
        {
            novo = (polinomio *)malloc(sizeof(polinomio));
            novo->coeficiente = z->coeficiente;
            novo->expoente = z->expoente;
            novo->prox = NULL;
            resultante = concatena(resultante, novo);
            z = z->prox;
        }
    }
    if (p == NULL && z != NULL)
    {
        resultante = concatena(resultante, z);
    }
    else if (p != NULL && z == NULL)
    {
        resultante = concatena(resultante, p);
    }
    return resultante;
}
void imprime_polinomio(polinomio *lista)
{
    polinomio *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Lista:\n");
        while (p != NULL)
        {
            printf("%dX%d + ", p->coeficiente, p->expoente);
            p = p->prox;
        }
        printf("0\n");
    }
}