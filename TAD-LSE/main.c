#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    nodo *l;
    l = inicializa();
    int opcao = 8;
    int valor;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um valor no final da Lista\n");
        printf("2 - Profundidade de um elemento\n");
        printf("3 - Imprime Lista\n");
        printf("4 - Conta nos\n");
        printf("5 - Libera lista\n");
        printf("6 - Remove valor\n");
        printf("7 - Insere valor ordenado\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            l = insere_fim(l, valor);
            break;
        case 2:
            printf("Digite um elemento\n");
            scanf("%d", &valor);
            int retorno = profundidade(l, valor);
            if (retorno == -1)
            {
                printf("Elemento nao encontrado\n");
            }
            else
            {
                printf("Profundidade elemento %d : %d\n", valor, retorno);
            }
            break;
        case 3:
            if (l == NULL)
            {
                printf("Lista vazia\n");
            }
            else
            {
                imprime_lista(l);
            }

            break;
        case 4:
            if (conta_nos(l) == -1)
            {
                printf("Lista vazia\n");
            }
            else
            {
                printf("Numero de nos : %d\n", conta_nos(l));
            }
            break;
        case 5:
            if (l == NULL)
            {
                printf("Lista vazia\n");
            }
            else
            {
                l = libera_lst(l);
                printf("Lista liberada\n");
            }
            break;
        case 6:
            if (l == NULL)
            {
                printf("Lista vazia\n");
            }
            else
            {
                printf("Digite um valor\n");
                scanf("%d", &valor);
                l = busca_rmv(l, valor);
            }
            break;
        case 7:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            l = insere_ordenado(l, valor);
            break;
        case 0:
            printf("Menu encerrado\n");
            break;

        default:
            printf("Opcao invalida, digite novamente\n");
            break;
        }
    }
    return 0;
}
