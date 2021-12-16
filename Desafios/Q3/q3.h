typedef struct valor nodo;

struct valor
{
    char dado;
    nodo *prox;
    nodo *ant;
};
nodo *insere_fim(nodo *l, char valor);
