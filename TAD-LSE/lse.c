#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

//arrumar função insere ordenada e liberalista

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
int profundidade(nodo *l, int valor)
{
    nodo *p;
    p = l;
    int cont = 0;
    if (l == NULL)
    {
        return (-1);
    }
    else
    {
        while (p != NULL && p->dado != valor)
        {
            cont++;
            p = p->prox;
        }
        if (p == NULL)
        {
            return (-1);
        }
        return (cont + 1);
    }
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
int conta_nos(nodo *l)
{
    nodo *p;
    p = l;
    int cont = 0;
    if (l == NULL)
    {
        return (-1);
    }
    else
    {
        while (p != NULL)
        {
            cont++;
            p = p->prox;
        }
        return (cont);
    }
}
nodo *libera_lst(nodo *l)
{
    nodo *p;
    p = l;
    while (p != NULL)
    {
        nodo *aux;
        aux = p;
        p = p->prox;
        free(aux);
    }
    l = NULL;
    return l;
}
nodo *busca_rmv(nodo *l, int valor)
{
    nodo *p;
    p = l;
    nodo *a;
    a = NULL;
    while (p != NULL && p->dado != valor)
    {
        a = p;
        p = p->prox;
    }
    if (a == NULL)
    {
        l = p->prox;
    }
    else if (p == NULL)
    {
        printf("Valor nao encontrado\n");
    }
    else
    {
        a->prox = p->prox;
        free(p);
    }
    return l;
}
nodo *insere_ordenado(nodo *l, int valor)
{
    nodo *p;
    p = l;
    nodo *ant;
    ant = NULL;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->prox = NULL;
    if (l == NULL)
    {
        return (novo);
    }
    while (p != NULL && p->dado < valor)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)
    {
        novo->prox = p;
        return (l);
    }
    if (p == NULL)
    {
        ant->prox = novo;
        return (l);
    }
    novo->prox = p;
    ant->prox = novo;
    return (l);
}