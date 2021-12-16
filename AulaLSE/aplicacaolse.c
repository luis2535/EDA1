#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg
{
    int valor;
    celula *prox;
};

celula *cria(int a)
{
    celula *b;
    b = (celula *)malloc(sizeof(celula));
    b->valor = a;
    b->prox = NULL;
    return (b);
}
celula *insere_fim(celula *lista, celula *novo)
{
    celula *p;
    p = lista;
    if (lista == NULL)
        return (novo);
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return (lista);
}
void imprime(celula *lista)
{
    celula *p;
    p = lista;
    while (p != NULL)
    {
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    }
}

int main()
{
    celula *lista;
    lista = NULL;
    lista = insere_fim(lista, cria(1));
    lista = insere_fim(lista, cria(2));
    lista = insere_fim(lista, cria(3));
    lista = insere_fim(lista, cria(4));
    imprime(lista);
    return 0;
}