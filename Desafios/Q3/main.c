#include "q3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    nodo *numero1;
    nodo *numero2;
    char valor1[50];
    char valor2[50];
    printf("Digite o primeiro numero flutuante");
    scanf("%[^\n]", valor1);
    printf("Digite o segundo numero flutuante");
    scanf("%[^\n]", valor2);
    for (int i = 0; strlen(valor1); i++)
    {
        numero1 = insere_fim(numero1, valor1[i]);
    }
    for (int i = 0; strlen(valor2); i++)
    {
        numero2 = insere_fim(numero2, valor2[i]);
    }
}