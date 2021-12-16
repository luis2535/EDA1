#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    nodo *l;
    nodo *l2;
    l2 = inicializa();
    l = inicializa();
    int opcao = -10;
    int valor, valor2;
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
        printf("8 - Troca posicao\n");
        printf("9 - Inverta 2 nos de posicao\n");
        printf("10 - Criar lista2.\n");
        printf("11 - Concatenar listas.\n");
        printf("12 - Imprimir lista2.\n");
        printf("13 - Move menor para inicio.\n");
        printf("14 - Ordena lista.\n");
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
        case 8:
            printf("Digite um valor para efetuar a troca com seu sucessor:\n");
            scanf("%d", &valor);
            l = troca(l, valor);
            break;
        case 9:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            printf("Digite um segundo valor\n");
            scanf("%d", &valor2);
            l = trocaNos(l, valor, valor2);
            break;
        case 10:
            printf("Digite um valor para inserir no inicio da lista:\n");
            scanf("%d", &valor);
            l2 = insere_fim(l2, valor);
            break;
        case 11:
            l = concatena(l, l2);
            printf("Lista 1 e 2 concatenadas!\n");
            break;
        case 12:
            if (l2 == NULL)
            {
                printf("Lista vazia\n");
            }
            else
            {
                imprime_lista(l2);
            }

            break;
        case 13:
            printf("Realizando operacao.\n");
            l = mover_menor(l);
            break;
        case 14:
            printf("Ordenando a lista.\n");
            l = ordena_lista(l);
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
