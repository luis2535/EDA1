#include "q2.h"
#include <stdio.h>
#include <stdlib.h>

nodo *troca(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
    }
    while (p != NULL && p->dado != valor)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor nao encontrado\n");
        return lista;
    }
    if (p->prox == NULL)
    {
        printf("Nao eh possivel trocar o valor com o sucessor pois eh o ultimo valor da lista");
        return lista;
    }
    if (p->ant == NULL)
    {
        p->ant = p->prox;
        p->prox = p->prox->prox;
        p->ant->prox = p;
        if (p->prox != NULL)
        {
            p->prox->ant = p;
        }
        p->ant->ant = NULL;
        return (p->ant);
    }
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    p->ant = p->prox;
    p->prox = p->prox->prox;
    if (p->prox != NULL)
    {
        p->prox->ant = p;
    }
    p->ant->prox = p;

    return lista;
}