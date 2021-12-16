#include "q3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

nodo *insere_fim(nodo *l, char valor)
{
    nodo *p;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;
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
    novo->ant = p;
    return (l);
}
nodo *somaresultante(nodo *numero1, nodo *numero2)
{
    nodo *p;
    nodo *n;
    nodo *resultante;
    p = numero1;
    n = numero2;
    while (p != NULL && p->dado != '.')
    {
        p = p->prox;
    }
    while (n != NULL && n->dado != '.')
    {
        n = n->prox;
    }
    while (n->prox != NULL && p->prox != NULL)
    {
        p->prox;
        n->prox;
    }
    if (p->prox == NULL && n->prox != NULL)
    {
        resultante = n;
    }
    else if (p->prox != NULL && n->prox == NULL)
    {
        resultante = p;
    }
    else
    {
        resultante->ant = NULL;
    }
}
