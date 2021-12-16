typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};
nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lse e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes trocadas