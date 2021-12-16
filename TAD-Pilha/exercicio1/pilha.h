typedef struct pilha Pilha;
typedef struct registro nodo;
struct registro
{
    char dado;
    nodo *prox;
};
struct pilha
{
    nodo *topo;
};
Pilha *cria();
int pop(Pilha *p, char *dado);
int push(Pilha *p, char dado);
int verifica(Pilha *p);
