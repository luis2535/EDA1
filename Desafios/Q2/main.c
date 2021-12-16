#include "q2.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sobrenome *nome;
    char str[50];
    printf("Digite o sobrenome");
    scanf("%s", str);
    for (int i = 0; i < sizeof(str); i++)
    {
        nome = insere_fim(nome, &str[i]);
    }
    int checagem;
    checagem = eFacil(nome);
    if (checagem == 0)
    {
        printf("Sobrenome nao eh facil");
    }
    else
    {
        printf("Sobrenome eh facil");
    }
    return 0;
}