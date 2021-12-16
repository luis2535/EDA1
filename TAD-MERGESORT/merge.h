typedef struct reg nodo;

struct reg
{
	int dado;
	nodo *prox;
};

nodo *insere_fim(nodo *l, int valor);
void imprime_lista(nodo *l);
nodo *inicializa();
nodo *mergeSort(nodo *lista);
nodo *split(nodo *lista);
nodo *merge(nodo *e, nodo *d);
