#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

nodo *cria_no(int chave)
{
    nodo *n;
    n = malloc(sizeof(nodo));
    n->esq = n->dir = NULL;
    n->chave = chave;
    return (n);
}
arvore insere(arvore r, nodo *novo)
{
    if (r == NULL)
    {
        return (novo);
    }
    if (novo->chave < r->chave)
    {
        insere(r->esq, novo);
    }
    else
    {
        insere(r->dir, novo);
    }
    return (r);
}
nodo *busca(arvore r, int chave)
{

    if (r == NULL)
    {
        return NULL;
    }
    if (chave == r->chave)
    {
        return (r);
    }
    else if (chave < r->chave)
    {
        return (busca(r->esq, chave));
    }
    else
    {
        return (busca(r->dir, chave));
    }
}