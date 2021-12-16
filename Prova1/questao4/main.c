#include "questao4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    nodo *l; // ponteiro para criacao de lista
    l = inicializa();
    int opcao = -10; //referencia do switch case
    float mediana;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Insira um aluno na lista.\n");
        printf("2 - Imprime lista.\n");
        printf("3 - Calcula Mediana\n");
        printf("0 - Encerra Menu\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            l = inserir_fim(l, criaAluno());
            break;
        case 2:
            imprime_lista(l);
            break;
        case 3:
            mediana = calcular_mediana(l);
            printf("A mediana eh: %.2f\n", mediana);
            break;
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