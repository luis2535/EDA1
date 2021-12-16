typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};

nodo *insere_fim(nodo *l, int valor);
void imprime_lista(nodo *l);
nodo *inicializa();
nodo *quickSort(nodo *lista);
nodo *particao(nodo *lista);
nodo *concatena(nodo *e, nodo *d);
