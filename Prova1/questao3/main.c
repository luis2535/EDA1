#include "questao3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    polinomio *l; // ponteiro para criacao de lista
    l = inicializa();
    int opcao = -10; //referencia do switch case
    int coeficiente; //recebe valor do coeficiente para atribuir a lista
    float x;         // recebe valor de x para calculo
    float soma;      // armazenar valor de soma
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um valor na lista de polinomios.\n");
        printf("2 - Imprime lista de polinomios.\n");
        printf("3 - Calcula x\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite um coeficiente\n");
            scanf("%d", &coeficiente);
            l = insere_fim(l, cria_nodo(coeficiente));
            break;

        case 2:
            imprime_lista(l);
            break;
        case 3:
            printf("Digite um valor de X para calculo:\n");
            scanf("%f", &x);
            soma = calcular(l, x);
            printf("O valor da soma eh: %.3f\n", soma);
        case 0:
            printf("Menu encerrado!\n");
            break;
        default:
            printf("Opcao invalida, digite novamente!\n");
            break;
        }
    }
    return 0;
}