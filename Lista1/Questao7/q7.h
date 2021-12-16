typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};

nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lse e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes trocadas
nodo *concatena(nodo *lista, nodo *lista2);          //funcao deve receber 2 listas, a segunda lista sera concatenada ao final da primeira
nodo *mover_menor(nodo *lista);                      //funcao deve receber uma lse, o menor valor dessa lse sera encontrado e sera enviado junto a lista e seu primeiro valor para a funcao trocaNos
nodo *ordena_lista(nodo *lista);                     /*funcao recebera uma lse e fara uma serie de iteracoes com a mesma, apos enviar a lista para o mover_menor para encontrar o menor valor, 
                                                     o menor valor sera concatenado em uma nova lista e sua cauda sera reenviada para a funcao mover_menor, a operacao se repetira ate que a lse esteja ordenada*/
