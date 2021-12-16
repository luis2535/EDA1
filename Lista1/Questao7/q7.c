#include "q7.h"
#include <stdio.h>
#include <stdlib.h>

nodo *trocaNos(nodo *lista, int valor1, int valor2)
{
    nodo *p;
    nodo *z;
    nodo *a1;
    nodo *a2;
    nodo *prox1;
    nodo *prox2;
    prox1 = NULL;
    prox2 = NULL;
    a1 = NULL;
    a2 = NULL;
    p = lista;
    z = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return lista;
    }
    if (valor1 == valor2)
    {
        printf("Valores invalidos.\n");
        return lista;
    }
    while (p != NULL && p->dado != valor1)
    {
        a1 = p;
        p = p->prox;
    }
    while (z != NULL && z->dado != valor2)
    {
        a2 = z;
        z = z->prox;
    }
    if (p == NULL || z == NULL)
    {
        printf("Um dos valores nao foi encontrado!\n");
        return lista;
    }
    if (a1 == z)
    {
        z->prox = p->prox;
        p->prox = z;
        if (a2 == NULL)
        {
            return p;
        }
        a2->prox = p;
        return lista;
    }
    if (a2 == p)
    {
        p->prox = z->prox;
        z->prox = p;
        if (a1 == NULL)
        {
            return z;
        }
        a1->prox = z;
        return lista;
    }
    if (a1 == NULL)
    {
        a2->prox = p;
        prox1 = p->prox;
        prox2 = z->prox;
        z->prox = prox1;
        p->prox = prox2;
        return z;
    }
    if (a2 == NULL)
    {
        a1->prox = z;
        prox1 = p->prox;
        prox2 = z->prox;
        z->prox = prox1;
        p->prox - prox2;
        return p;
    }
    a1->prox = z;
    a2->prox = p;
    prox1 = p->prox;
    prox2 = z->prox;
    p->prox = prox2;
    z->prox = prox1;
    return lista;
}
nodo *concatena(nodo *lista, nodo *lista2)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        return lista2;
    }
    if (lista2 == NULL)
    {
        printf("Lista2 vazia!\n");
        return lista;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = lista2;
    return lista;
}

nodo *mover_menor(nodo *lista)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return lista;
    }
    int primeiro, menor;
    primeiro = p->dado;
    menor = p->dado;
    while (p != NULL)
    {
        if (p->dado < menor)
        {
            menor = p->dado;
        }
        p = p->prox;
    }
    if (primeiro == menor)
    {
        return lista;
    }
    return (trocaNos(lista, primeiro, menor));
}
nodo *ordena_lista(nodo *lista)
{
    nodo *p;
    nodo *novo;
    nodo *resultante;
    resultante = NULL;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return lista;
    }
    while (p != NULL)
    {
        p = mover_menor(p);
        novo = (nodo *)malloc(sizeof(nodo));
        novo->dado = p->dado;
        novo->prox = NULL;
        resultante = concatena(resultante, novo);
        p = p->prox;
    }
    return resultante;
}