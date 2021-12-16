#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    Tarefa *l;
    l = NULL;
    int id, dia, mes, ano, hora1, minuto1, hora2, minuto2;
    char nome[30];
    int opcao = -10;
    while (opcao != 0)
    {
        printf("\nEscolha uma Opcao do Menu\n");
        printf("----------------------------------------\n");
        printf("1 - Incluir nova tarefa.\n");
        printf("2 - Visualizar tarefas cadastradas.\n");
        printf("3 - Excluir tarefa.\n");
        printf("4 - Editar tarefa.\n");
        printf("0 - Sair.\n");
        printf("-----------------------------------------\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite a ID:\n");
            scanf("%d", &id);
            printf("Digite o nome:\n");
            scanf(" %[^\n]", nome);
            printf("Digite a duracao.\n");
            printf("Horas: ");
            scanf("%d", &hora1);
            printf("Minutos: ");
            scanf("%d", &minuto1);
            printf("Digite a deadline.\n");
            printf("Dia:");
            scanf("%d", &dia);
            printf("Mes:");
            scanf("%d", &mes);
            printf("Ano:");
            scanf("%d", &ano);
            printf("Horas: ");
            scanf("%d", &hora2);
            printf("Minutos: ");
            scanf("%d", &minuto2);
            l = insereTarefa(l, criaTarefas(id, criaReg(nome, criaHoraminuto(hora1, minuto1), criaTempo(dia, mes, ano, criaHoraminuto(hora2, minuto2)))), id);
            break;
        case 2:
            imprimeLista(l);
            break;
        case 3:
            if (l != NULL)
            {
                printf("Digite o id da tarefa que deseja excluir:\n");
                imprimeNome(l);
                scanf("%d", &id);
                l = removerTarefa(l, id);
            }
            else
            {
                printf("Lista vazia!\n");
            }
            break;
        case 4:
            if (l != NULL)
            {
                printf("Digite o id da tarefa que deseja alterar:\n");
                imprimeNome(l);
                scanf("%d", &id);
                l = encontraTarefa(l, id);
            }
            else
            {
                printf("Lista vazia!\n");
            }
            break;
        case 0:
            printf("Sistema finalizado!\n");
            break;
        default:
            printf("Opcao invalida, digite novamente");
        }
    }
    return 0;
}