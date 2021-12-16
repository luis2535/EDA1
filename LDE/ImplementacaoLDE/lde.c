#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

nodo *inicializa()
{
    nodo *p;
    p = NULL;
    return p;
}
nodo *inserir_fim(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    if (p == NULL)
    {
        return (novo);
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    novo->ant = p;
    return (lista);
}
nodo *inserir_inicio(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->ant = NULL;
    novo->dado = valor;
    novo->prox = NULL;
    if (p == NULL)
    {
        return novo;
    }
    novo->prox = p;
    p->ant = novo;
    return (novo);
}
nodo *insere_ordenado(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->ant = NULL;
    novo->dado = valor;
    novo->prox = NULL;
    if (p == NULL)
    {
        return novo;
    }
    while (p->prox != NULL && p->dado <= valor)
    {
        p = p->prox;
    }
    if (p->prox == NULL)
    {
        if (valor <= p->dado)
        {
            if (p->ant == NULL)
            {
                return (inserir_inicio(lista, valor));
            }
            else
            {
                novo->prox = p;
                novo->ant = p->ant;
                p->ant->prox = novo;
                p->ant = novo;
            }
        }
        else
        {
            return (inserir_fim(lista, valor));
        }
    }
    else if (p->ant == NULL)
    {
        return (inserir_inicio(lista, valor));
    }
    else
    {
        novo->prox = p;
        novo->ant = p->ant;
        p->ant->prox = novo;
        p->ant = novo;
    }
    return (lista);
}
void imprime_lista(nodo *lista)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Lista:\n");
        while (p != NULL)
        {
            printf("Valor: %d\n", p->dado);
            p = p->prox;
        }
    }
}
int busca_posicao(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    int cont = 0;
    if (p == NULL)
    {
        return -1;
    }
    while (p != NULL && p->dado != valor)
    {
        p = p->prox;
        cont++;
    }
    if (p == NULL)
    {
        return -2;
    }
    if (p->ant == NULL)
    {
        return 1;
    }
    return (cont + 1);
}
nodo *altera_valor(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return lista;
    }
    while (p != NULL && p->dado != valor)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor nao encontrado.\n");
        return lista;
    }
    int novoValor;
    printf("Digite o novo valor da posicao:\n");
    scanf("%d", &novoValor);
    p->dado = novoValor;
    return lista;
}
nodo *remove_valor(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return lista;
    }
    while (p != NULL && valor != p->dado)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor não encontrado.\n");
        return lista;
    }
    if (p->ant == NULL)
    {
        if (p->prox != NULL)
        {
            lista = p->prox;
            lista->ant = NULL;
        }
        else
        {
            lista = NULL;
        }
    }
    else
    {
        p->ant->prox = p->prox;
        if (p->prox != NULL)
        {
            p->prox->ant = p->ant;
        }
    }
    free(p);
    return (lista);
}
nodo *troca(nodo *lista, int valor)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
    }
    while (p != NULL && p->dado != valor)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Valor nao encontrado\n");
        return lista;
    }
    if (p->prox == NULL)
    {
        printf("Nao eh possivel trocar o valor com o sucessor pois eh o ultimo valor da lista");
        return lista;
    }
    if (p->ant == NULL)
    {
        p->ant = p->prox;
        p->prox = p->prox->prox;
        p->ant->prox = p;
        if (p->prox != NULL)
        {
            p->prox->ant = p;
        }
        p->ant->ant = NULL;
        return (p->ant);
    }
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    p->ant = p->prox;
    p->prox = p->prox->prox;
    if (p->prox != NULL)
    {
        p->prox->ant = p;
    }
    p->ant->prox = p;

    return lista;
}
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