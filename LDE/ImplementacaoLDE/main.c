#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

int main()
{
    nodo *lista;
    nodo *lista2;
    lista = inicializa();
    lista2 = inicializa();
    int opcao = 10;
    int valor, valor2;

    while (opcao != 0)
    {
        printf("\n");
        printf("1 - Inserir no inicio.\n");
        printf("2 - Inserir no fim.\n");
        printf("3 - Inserir ordenado.\n");
        printf("4 - Buscar valor.\n");
        printf("5 - Mudar um valor.\n");
        printf("6 - Remover um valor.\n");
        printf("7 - Imprimir a lista.\n");
        printf("8 - Troca posicao com o sucessor\n");
        printf("9 - Trocar 2 nos de posicao.\n");
        printf("0 - Finalizar programa.\n");
        printf("\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor para inserir no inicio da lista:\n");
            scanf("%d", &valor);
            lista = inserir_inicio(lista, valor);
            break;
        case 2:

            printf("Digite um valor para inserir ao fim da lista:\n");
            scanf("%d", &valor);
            lista = inserir_fim(lista, valor);
            break;
        case 3:

            printf("Digite um valor para inserir ordenado:\n");
            scanf("%d", &valor);
            lista = insere_ordenado(lista, valor);
            break;
        case 4:
            printf("Digite um valor para procurar sua posicao:\n");
            scanf("%d", &valor);
            int posicao = busca_posicao(lista, valor);
            if (posicao == -2)
            {
                printf("Elemento nao encontrado\n");
            }
            else if (posicao == -1)
            {
                printf("Lista Vazia\n");
            }
            else
            {
                printf("Posicao: %d\n", posicao);
            }

            break;
        case 5:
            printf("Digite o valor que deseja alterar:\n");
            scanf("%d", &valor);
            lista = altera_valor(lista, valor);
            break;
        case 6:
            printf("Digite o valor que deseja remover da lista:\n");
            scanf("%d", &valor);
            lista = remove_valor(lista, valor);
            break;
        case 7:
            imprime_lista(lista);
            break;
        case 8:
            printf("Digite um valor para trocar com seu sucessor:\n");
            scanf("%d", &valor);
            lista = troca(lista, valor);
            break;
        case 9:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            printf("Digite um segundo valor\n");
            scanf("%d", &valor2);
            lista = trocaNos(lista, valor, valor2);
            break;

        case 0:
            printf("Programa finalizado!!");
            break;
        default:
            printf("Opcao invalida, digite novamente!");
            break;
        }
    }
}
