typedef struct reg nodo;

struct reg
{
	int dado;
	nodo *prox;
};

nodo *insere_fim(nodo *l, int valor);
int profundidade(nodo *l, int valor);
void imprime_lista(nodo *l);
nodo *inicializa();
int conta_nos(nodo *l);
nodo *libera_lst(nodo *l);
nodo *busca_rmv(nodo *l, int valor);
nodo *insere_ordenado(nodo *l, int valor);
nodo *troca(nodo *lista, int valor);				 //funcao deve receber uma lse e um valor, esse valor sera procurado na lista e seu valor sera invertido com seu sucessor
nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lse e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes
nodo *concatena(nodo *lista, nodo *lista2);			 //funcao deve receber 2 listas, a segunda lista sera concatenada ao final da primeira
nodo *mover_menor(nodo *lista);						 //funcao deve receber uma lse, o menor valor dessa lse sera encontrado e sera enviado junto a lista e seu primeiro valor para a funcao trocaNos
nodo *ordena_lista(nodo *lista);					 /*funcao recebera uma lse e fara uma serie de iteracoes com a mesma, apos enviar a lista para o mover_menor para encontrar o menor valor, 
                                                     o menor valor sera concatenado em uma nova lista e sua cauda sera reenviada para a funcao mover_menor, a operacao se repetira ate que a lse esteja ordenada*/