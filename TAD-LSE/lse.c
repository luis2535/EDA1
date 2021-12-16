#include "lse.h"
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
nodo *troca(nodo *lista, int valor)
{
    nodo *p;
    nodo *a;
    a = NULL;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return (lista);
    }
    while (p != NULL && p->dado != valor)
    {
        a = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor nao encontrado!\n");
        return (lista);
    }
    if (p->prox == NULL)
    {
        printf("Nao eh possivel fazer a troca pois esse eh o ultimo valor da lista\n");
        return (lista);
    }
    if (a == NULL)
    {
        a = p;
        p = p->prox;
        a->prox = p->prox;
        p->prox = a;
        return p;
    }
    a->prox = p->prox;
    p->prox = p->prox->prox;
    a->prox->prox = p;
    return (lista);
}
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