#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    nodo *l;
    l = inicializa();
    int opcao = -10;
    int valor, valor2;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um valor no final da Lista\n");
        printf("2 - Ordena lista\n");
        printf("3 - Imprime Lista\n");
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
            printf("Executando merge Sort\n");
            nodo *p;
            l = mergeSort(l);
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
