#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    Pilha *p;
    p = cria();
    int opcao = -10;
    char valor[255];
    int status = 1;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira uma expressao.\n");
        printf("2 - Verifica expressao\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite um valor para adicionar na pilha:\n");
            scanf(" %[^\n]", valor);
            //o for envia os elementos da string 1 a 1 para a pilha
            for (int i = 0; i < strlen(valor); i++)
            {
                status = push(p, valor[i]);
            }
            break;
        case 2:
            status = verifica(p);
            if (status)
            {
                printf("A expressao aritmetica dos parenteses esta correta!\n");
            }
            else
            {
                printf("A expressao aritmetica dos parenteses esta incorreta!\n");
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