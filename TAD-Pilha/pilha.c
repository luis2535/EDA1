#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
Pilha *cria()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
int push(Pilha *p, int dado)
{
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return (1);
}
int pop(Pilha *p, int *dado)
{
    if (p->topo == NULL)
    {
        return (0);
    }
    else
    {
        *dado = p->topo->dado;
        nodo *temp;
        temp = p->topo;
        p->topo = temp->prox;
        free(temp);
        return (1);
    }
}
