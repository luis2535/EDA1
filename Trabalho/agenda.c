#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//funcao criaHoraminuto recebe 2 inteiros e aloca uma struct Horaminuto que sera usada na duracao da tarefa e do deadline
Horaminuto *criaHoraminuto(int hora, int minuto)
{
    Horaminuto *novo;
    novo = (Horaminuto *)malloc(sizeof(Horaminuto));
    novo->HORA = hora;
    novo->MINUTO = minuto;
    return novo;
}
//funcao criaTempo recebe 3 inteiro e uma struct e sera alocado uma struct Tempo, os inteiros serao dia, mes e ano e a struct recebida tera parametros de duracao(hora e minuto)
Tempo *criaTempo(int dia, int mes, int ano, Horaminuto *horas)
{
    Tempo *novo;
    novo = (Tempo *)malloc(sizeof(Tempo));
    novo->DIA = dia;
    novo->MES = mes;
    novo->ANO = ano;
    novo->HORAS = horas;
    return novo;
}
//funcao criaReg recebe um char com o nome e 2 structs e aloca uma struct Reg, a primeira struct e o parametro de duracao e a segunda o parametro da deadline
Reg *criaReg(char *nome, Horaminuto *duracao, Tempo *deadline)
{
    Reg *novo;
    novo = (Reg *)malloc(sizeof(Reg));
    strcpy(novo->NOME, nome);
    novo->DURACAO = duracao;
    novo->DEADLINE = deadline;
    return novo;
}
//funcao criaTarefa recebe um inteiro que sera o id e uma struct Reg, com esses parametros sera alocada uma struct Tarefa
Tarefa *criaTarefas(int id, Reg *dados)
{
    Tarefa *novo;
    novo = (Tarefa *)malloc(sizeof(Tarefa));
    novo->ID = id;
    novo->DADOS = dados;
    novo->prox = NULL;
    return novo;
}
//funcao insereTarefa recebera 2 structs Tarefa, a primeira sera uma LSE e a segunda sera um nodo que sera encadeado ao fim dessa LSE, recebera tambem um id, se esse id ja estiver cadastrado, o novo nodo nao sera encadeado
Tarefa *insereTarefa(Tarefa *l, Tarefa *novo, int id)
{
    Tarefa *p;
    p = l;
    if (p == NULL)
    {
        return novo;
    }
    while (p->prox != NULL && p->ID != id)
    {
        p = p->prox;
    }
    if (p->ID == id)
    {
        printf("ID ja cadastrado, nova tarefa nao registrada.\n");
    }
    else
    {
        p->prox = novo;
    }
    return l;
}
//funcao imprimeLista recebe uma struct Tarefa que possui a LSE, se a lista nao esta vazia, a funcao imprime dado a dado de cada nodo, se estiver vazia imprime Lista vazia
void imprimeLista(Tarefa *l)
{
    Tarefa *p;
    p = l;
    int cont = 1;
    if (p != NULL)
    {
        printf("Lista : \n");
        while (p != NULL)
        {
            printf("\n");
            printf("%d - ID: %d\n", cont, p->ID);
            printf("Nome: %s Duracao: %d hora %d minutos\n", p->DADOS->NOME, p->DADOS->DURACAO->HORA, p->DADOS->DURACAO->MINUTO);
            printf("Deadline: %d/%d/%d %d horas %d minutos\n", p->DADOS->DEADLINE->DIA, p->DADOS->DEADLINE->MES, p->DADOS->DEADLINE->ANO, p->DADOS->DEADLINE->HORAS->HORA, p->DADOS->DEADLINE->HORAS->MINUTO);
            printf("\n");
            p = p->prox;
            cont++;
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}
/*funcao removerTarefa recebe por parametro uma struct Tarefa que possui a LSE e um inteiro que contem a id, se o id for encontrado, a lista sera reencadeada, 
o valor anterior do nodo tera como proximo valor o proximo valor do nodo e a memoria do nodo sera liberada e a lista sem esse nodo sera retornada, se o id nao
 for encontrado sera printado um aviso e sera retornada a lista completa*/
Tarefa *removerTarefa(Tarefa *l, int id)
{
    Tarefa *p;
    p = l;
    Tarefa *a;
    a = NULL;
    while (p != NULL && p->ID != id)
    {
        a = p;
        p = p->prox;
    }
    if (a == NULL)
    {
        l = p->prox;
    }
    else if (p == NULL)
    {
        printf("ID nao encontrada!\n");
    }
    else
    {
        a->prox = p->prox;
        free(p);
    }
    return l;
}
/*funcao encontraTarefa recebera como parametro uma struct Tarefa que possui a LSE e um inteiro que possui o id, a funcao ira procurar se esse id esta presente na lista
imprimindo na tela um aviso caso nao seja encontrado, se encontrar ele fara a chamada da funcao editarTarefa enviando esse nodo como parametro e apos esse nodo ser editado,
a funcao fara o retorno da lista*/
Tarefa *encontraTarefa(Tarefa *l, int id)
{
    Tarefa *p;
    p = l;
    if (p == NULL)
    {
        return l;
    }
    while (p != NULL && p->ID != id)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("ID nao encontrada!\n");
    }
    else
    {
        p = editarTarefa(p);
    }
    return l;
}
/*funcao editarTarefa recebe uma struct Tarefa, essa struct contem uma LSE, porem apenas o primeiro nodo dessa LSE sera editado, um menu de opcoes sera apresentado
e podera ser escolhido que dado sera alterado, para cada dado, devem ser escrito seus valores e eles serao escritos por cima dos atuais, ao digitar 0, o menu sera
encerrado e sera retornada essa LSE com os dados do primeiro nodo alterado*/
Tarefa *editarTarefa(Tarefa *l)
{
    Tarefa *p;
    p = l;
    int opcao = 1;
    char nome[30];
    int dia, mes, ano, horas, minuto;
    while (opcao != 0)
    {
        printf("\nDigite o numero correspondente a que informacao deseja alterar:\n");
        printf("1 - Nome.\n");
        printf("2 - Duracao.\n");
        printf("3 - Deadline.\n");
        printf("0 - Finalizar edicao.\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nVoce escolheu editar o nome.\n");
            printf("Digite o novo nome:\n");
            scanf(" %[^\n]", nome);
            strcpy(p->DADOS->NOME, nome);
            printf("Nome alterado com sucesso!\n");
            break;
        case 2:
            printf("\nVoce escolheu editar a duracao.\n");
            printf("Digite a nova duracao.\n");
            printf("Horas: ");
            scanf("%d", &horas);
            printf("Minuto: ");
            scanf("%d", &minuto);
            p->DADOS->DURACAO = criaHoraminuto(horas, minuto);
            printf("Duracao alterada com sucesso!\n");
            break;
        case 3:
            printf("\nVoce escolheu editar a deadline.\n");
            printf("Digite a nova deadline.\n");
            printf("Dia: ");
            scanf("%d", &dia);
            printf("Mes: ");
            scanf("%d", &mes);
            printf("Ano: ");
            scanf("%d", &ano);
            printf("Horas: ");
            scanf("%d", &horas);
            printf("Minuto: ");
            scanf("%d", &minuto);
            p->DADOS->DEADLINE = criaTempo(dia, mes, ano, criaHoraminuto(horas, minuto));
            printf("Duracao alterada com sucesso!\n");
            break;
        case 0:
            printf("Saindo da operacao de edicao.\n");
            break;
        default:
            printf("Operacao invalida, digite novamente.\n");
        }
    }
    return p;
}
/* a funcao imprimeNome recebe uma struct Tarefa que possui uma LSE e tem funcionamento similar a funcao imprimeLista, a diferença eh que nesse caso apenas
os dados ID e Nome de cada nodo serao impressos na tela, essa funcao sera utilizada na main quando for necessario apenas ver rapidamente os dados que estao 
salvos para ser chamada uma funcao de remocao ou edicao de dados*/
void imprimeNome(Tarefa *l)
{
    Tarefa *p;
    p = l;
    int cont = 1;
    printf("Lista : \n");
    while (p != NULL)
    {
        printf("ID: %d Nome: %s\n", p->ID, p->DADOS->NOME);
        p = p->prox;
    }
}