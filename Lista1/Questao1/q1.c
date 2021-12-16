#include "q1.h"
#include <stdio.h>
#include <stdlib.h>

nodo *troca(nodo *lista, int valor)
{
    nodo *p;
    nodo *a;
    a = NULL;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return (lista);
    }
    while (p != NULL && p->dado != valor)
    {
        a = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor nao encontrado!\n");
        return (lista);
    }
    if (p->prox == NULL)
    {
        printf("Nao eh possivel fazer a troca pois esse eh o ultimo valor da lista\n");
        return (lista);
    }
    if (a == NULL)
    {
        a = p;
        p = p->prox;
        a->prox = p->prox;
        p->prox = a;
        return p;
    }
    a->prox = p->prox;
    p->prox = p->prox->prox;
    a->prox->prox = p;
    return (lista);
}