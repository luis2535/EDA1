typedef struct reg nodo;
struct reg
{
    int dado;
    nodo *prox;
    nodo *ant;
};
nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lde e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes trocadas