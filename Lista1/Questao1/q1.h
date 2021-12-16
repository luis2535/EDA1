typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};

nodo *troca(nodo *lista, int valor); //funcao deve receber uma lse e um valor, esse valor sera procurado na lista e seu valor sera invertido com seu sucessor