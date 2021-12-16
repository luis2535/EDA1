#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
//aloca a pilha na memoria
Pilha *cria()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
//adiciona um elemento no topo da pilha
int push(Pilha *p, char dado)
{
    nodo *novo;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return (1);
}
//remove o primeiro elemento do topo da pilha
int pop(Pilha *p, char *dado)
{
    if (p->topo == NULL)
    {
        return (0);
    }
    else
    {
        *dado = p->topo->dado;
        nodo *temp;
        temp = p->topo;
        p->topo = temp->prox;
        free(temp);
        return (1);
    }
}
/*verifica se a expressao de parenteses esta correta atraves da remocao dos nos do topo da lista, a cada  '(' que se remove na lista se adiciona 1 ao contador
e a cada ')' se remove 1 da pilha, porem se o contador da lista esta em 0 e se remove um '(', a contagem sempre estara incorreta e nesse caso todos os elementos serao
removidos da lista e retornara status 0 (incorreto), se ao final do while o contador for 0 sera retornado status 1 (correto), se for diferente sera retornado status 0
*/
int verifica(Pilha *p)
{
    if (p->topo == NULL)
    {
        return 0;
    }
    char dado;
    int abertura = 0;
    while (pop(p, &dado))
    {
        if (dado == '(')
        {
            if (abertura == 0)
            {
                while (pop(p, &dado))
                {
                }
                return 0;
            }
            abertura++;
        }
        else if (dado == ')')
        {
            abertura--;
        }
    }
    if (abertura == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
