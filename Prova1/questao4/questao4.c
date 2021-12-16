#include "questao4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

nodo *inicializa()
{
    nodo *p;
    p = NULL;
    return p;
}
nodo *criaAluno()
{
    nodo *novo;
    Aluno *alunonovo;
    int matricula;
    char nome[50];
    novo = (nodo *)malloc(sizeof(nodo));
    printf("Digite uma matricula\n");
    scanf("%d", &matricula);
    printf("Digite um nome\n");
    gets(nome);
    alunonovo->matricula = matricula;
    strcpy(alunonovo->nome, nome[50]);
    printf("Digite as 3 notas desse aluno:\n");
    float notas[3];
    for (int i = 0; i < 3; i++)
    {
        printf("%d nota:\n", i + 1);
        scanf("%f", &notas[i]);
        alunonovo->notas[i] = notas[i];
    }
    novo->prox = NULL;
    novo->aluno = alunonovo;
    novo->ant = NULL;
    return (novo);
}
nodo *inserir_fim(nodo *lista, nodo *novo)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        return (novo);
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    novo->ant = p;
    return (lista);
}
void imprime_lista(nodo *lista)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Lista:\n");
        while (p != NULL)
        {
            printf("Aluno: %d : %s\nNotas: %.2f %.2f %.2f", p->aluno->matricula, p->aluno->nome, p->aluno->notas[0], p->aluno->notas[1], p->aluno->notas[2]);
            p = p->prox;
        }
    }
}
float calcular_mediana(nodo *l)
{
    nodo *p;
    p = l;
    float todasNotas[100];
    int cont = 0;
    if (p == NULL)
    {
        printf("Lista vazia!\n");
        return -1;
    }
    while (p != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            todasNotas[cont] = p->aluno->notas[i];
            cont++;
        }
        p = p->prox;
    }
    int aux, i, j;
    for (i = 1; i < cont; i++) //insertion sort
    {
        aux = todasNotas[i];
        for (j = i - 1; (j >= 0) && (aux < todasNotas[j]); j--)
        {
            todasNotas[j + 1] = todasNotas[j];
        }
        todasNotas[j + 1] = aux;
    }
    float mediana;
    if (cont % 2 == 1)
    {
        mediana = todasNotas[cont / 2];
    }
    else
    {
        mediana = (todasNotas[cont / 2 - 1] + todasNotas[cont / 2]) / 2;
    }
    return mediana;
}
