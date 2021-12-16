#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Pilha *p;
    p = cria();
    int opcao = -10;
    int valor;
    int status = 1;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um valor na pilha.\n");
        printf("2 - Remova um valor da pilha.\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite um valor para adicionar na pilha:\n");
            scanf("%d", &valor);
            status = push(p, valor);
            if (status)
            {
                printf("%d adicionado a pilha\n", p->topo->dado);
            }
            else
            {
                printf("Nao foi possivel adicionar valor!\n");
            }

            break;
        case 2:
            status = pop(p, &valor);
            if (status)
            {
                printf("%d removido da pilha\n", valor);
            }
            else
            {
                printf("Lista vazia, nao foi possivel remover valor!\n");
            }
            break;
        case 0:
            printf("Menu encerrado!\n");
            break;
        default:
            printf("Opcao invalida, digite novamente!\n");
            break;
        }
    }
}