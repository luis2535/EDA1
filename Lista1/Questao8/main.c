#include "q8.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    polinomio *p1;
    polinomio *p2;
    polinomio *soma;
    p1 = inicializa();
    p2 = inicializa();
    soma = inicializa();
    int coeficiente, expoente;
    int opcao = -10;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um valor no polinomio 1.\n");
        printf("2 - Insira um valor no polinomio 2.\n");
        printf("3 - Imprime polinomio 1.\n");
        printf("4 - Imprime polinomio 2.\n");
        printf("5 - Soma polinomios 1 e 2.\n");
        printf("6 - Imprime polinomio resultante.\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite o coeficiente:\n");
            scanf("%d", &coeficiente);
            printf("Digite o expoente.\n");
            scanf("%d", &expoente);
            p1 = insere_ordenado(p1, cria_nodo(coeficiente, expoente));
            break;
        case 2:
            printf("Digite o coeficiente:\n");
            scanf("%d", &coeficiente);
            printf("Digite o expoente.\n");
            scanf("%d", &expoente);
            p2 = insere_ordenado(p2, cria_nodo(coeficiente, expoente));
            break;

        case 3:
            imprime_polinomio(p1);
            break;
        case 4:
            imprime_polinomio(p2);
            break;
        case 5:
            printf("Voce escolhe a opcao somar polinomios.\n");
            soma = somaPolinomio(p1, p2);
            break;
        case 6:
            imprime_polinomio(soma);
            break;
        case 0:
            printf("Menu finalizado\n");
            break;
        default:
            printf("Opcao invalida, digite novamente\n");
            break;
        }
    }
    return 0;
}