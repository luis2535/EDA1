#include "q5.h"
#include <stdio.h>
#include <stdlib.h>

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
        return lista;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = lista2;
    return lista;
}