#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

nodo *inicializa()
{
    nodo *p;
    p = NULL;
    return (p);
}

nodo *insere_fim(nodo *l, int valor)
{
    nodo *p;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->prox = NULL;
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
void imprime_lista(nodo *l)
{
    nodo *p;
    p = l;
    printf("Lista : \n");
    while (p != NULL)
    {
        printf("Valor: %d\n", p->dado);
        p = p->prox;
    }
}

nodo *split(nodo *lista)
{
    nodo *x, *y, *p;
    x = y = lista;
    if (lista == NULL)
    {
        return lista;
    }
    while (y->prox != NULL)
    {
        y = y->prox;
        if (y->prox != NULL)
        {
            x = x->prox;
            y = y->prox;
        }
    }
    p = x->prox;
    x->prox = NULL;
    return (p);
}
nodo *mergeSort(nodo *lista)
{
    nodo *e, *d, *mid;
    if (lista == NULL || lista->prox == NULL)
    {
        return lista;
    }
    mid = split(lista);
    e = mergeSort(lista);
    d = mergeSort(mid);
    lista = merge(e, d);
    return (lista);
}
nodo *merge(nodo *e, nodo *d)
{
    nodo *l, *p;
    l = NULL;
    while (e != NULL && d != NULL)
    {
        if (e->dado < d->dado)
        {
            if (l == NULL)
            {
                p = l = e;
                e = e->prox;
            }
            else
            {
                p->prox = e;
                e = e->prox;
                p = p->prox;
            }
        }
        else
        {
            if (l == NULL)
            {
                p = l = d;
                d = d->prox;
            }
            else
            {
                p->prox = d;
                d = d->prox;
                p = p->prox;
            }
        }
    }
    if (e == NULL)
    {
        while (d != NULL)
        {
            p->prox = d;
            d = d->prox;
            p = p->prox;
        }
    }
    if (d == NULL)
    {
        while (e != NULL)
        {
            p->prox = e;
            e = e->prox;
            p = p->prox;
        }
    }
    return l;
}
