typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};
nodo *concatena(nodo *lista, nodo *lista2); //funcao deve receber 2 listas, a segunda lista sera concatenada ao final da primeira