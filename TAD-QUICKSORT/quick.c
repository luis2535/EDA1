#include "quick.h"
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

nodo *particao(nodo *lista)
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
nodo *quickSort(nodo *lista)
{
    nodo *pivo;
    if (lista == NULL || lista->prox == NULL)
    {
        return lista;
    }
    pivo = particao(lista);
    lista = quickSort(lista);
    pivo = quickSort(pivo);
    lista = concatena(lista, pivo);
    return (lista);
}
nodo *concatena(nodo *e, nodo *d)
{
    nodo *p;
    p = e;
    if (p == NULL)
    {
        return d;
    }
    if (d == NULL)
    {
        return e;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = d;
    return e;
}