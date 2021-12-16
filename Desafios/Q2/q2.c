#include "q2.h"
#include <stdio.h>
#include <stdlib.h>

sobrenome *insere_fim(sobrenome *nome, char *adicionar)
{
    sobrenome *p;
    sobrenome *novo;
    novo = (sobrenome *)malloc(sizeof(sobrenome));
    novo->letra = *adicionar;
    novo->prox = NULL;
    p = nome;
    if (nome == NULL)
    {
        return (novo);
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return (nome);
}
int eFacil(sobrenome *l)
{
    sobrenome *p = l;
    int facil = 1;
    while (p->prox != NULL)
    {

        if (p->letra != 'a' && p->letra != 'e' && p->letra != 'i' && p->letra != 'o' && p->letra != 'u')
        {
            if (p->prox->letra != 'a' && p->prox->letra != 'e' && p->prox->letra != 'i' && p->prox->letra != 'o' && p->prox->letra != 'u')
            {
                facil = 0;
            }
        }
        p = p->prox;
    }

    return facil;
}