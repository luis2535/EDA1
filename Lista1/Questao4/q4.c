#include "q4.h"
#include <stdio.h>
#include <stdlib.h>

nodo *trocaNos(nodo *lista, int valor1, int valor2)
{
    nodo *p;
    nodo *z;
    nodo *prox1;
    nodo *ant1;
    ant1 = NULL;
    prox1 = NULL;
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
        p = p->prox;
    }
    while (z != NULL && z->dado != valor2)
    {
        z = z->prox;
    }
    if (p == NULL || z == NULL)
    {
        printf("Um dos valores nao foi encontrado!\n");
        return lista;
    }
    if (p->prox == z)
    {
        if (p->ant != NULL)
        {
            p->ant->prox = z;
        }
        p->prox = z->prox;
        if (z->prox != NULL)
        {
            z->prox->ant = p;
        }
        z->ant = p->ant;
        z->prox = p;
        p->ant = z;
        if (z->ant == NULL)
        {
            return z;
        }
        return lista;
    }
    if (z->prox == p)
    {
        if (z->ant != NULL)
        {
            z->ant->prox = p;
        }
        z->prox = p->prox;
        if (p->prox != NULL)
        {
            p->prox->ant = z;
        }
        p->ant = z->ant;
        p->prox = z;
        z->ant = p;
        if (p->ant == NULL)
        {
            return p;
        }
        return lista;
    }
    if (p->ant != NULL)
    {
        p->ant->prox = z;
    }
    if (z->ant != NULL)
    {
        z->ant->prox = p;
    }
    if (p->prox != NULL)
    {
        p->prox->ant = z;
    }
    if (z->prox != NULL)
    {
        z->prox->ant = p;
    }
    prox1 = p->prox;
    p->prox = z->prox;
    z->prox = prox1;
    ant1 = p->ant;
    p->ant = z->ant;
    z->ant = ant1;
    if (z->ant == NULL)
    {
        return z;
    }
    if (p->ant == NULL)
    {
        return p;
    }
    return lista;
}