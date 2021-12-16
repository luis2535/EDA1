#include <stdlib.h>
#include <stdio.h>
#include "q4.h"

// Dupla com Henrique Sant Anna
int main()
{
    Fibonacci *lista;
    lista = inicializa();
    int n;
    int f0 = 1;
    int f1 = 1;
    int anterior;
    printf("Digite os N valores de fibonnaci que deseja imprimir:\n");
    scanf("%d", &n);
    if (n == 1)
    {
        lista = criaLSE(lista, f0);
    }
    else if (n == 2)
    {
        lista = criaLSE(lista, f0);
        lista = criaLSE(lista, f1);
    }
    else
    {
        lista = criaLSE(lista, f0);
        lista = criaLSE(lista, f1);
        for (int i = 2; i < n; i++)
        {
            anterior = f1;
            f1 = f1 + f0;
            f0 = anterior;
            if (ehprimo(f1) == 1)
            {
                lista = criaLSE(lista, f1);
            }
        }
    }
    imprime_lista(lista);
    return 0;
}
