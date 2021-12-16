typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};

nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lse e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes trocadas
nodo *mover_menor(nodo *lista);                      //funcao deve receber uma lse, o menor valor dessa lse sera encontrado e sera enviado junto a lista e seu primeiro valor para a funcao trocaNos
