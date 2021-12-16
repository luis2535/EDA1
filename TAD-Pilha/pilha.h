typedef struct pilha Pilha;
typedef struct registro nodo;
struct registro
{
    int dado;
    nodo *prox;
};
struct pilha
{
    nodo *topo;
};

Pilha *cria();                //aloca a pilha na memoria
int pop(Pilha *p, int *dado); //remove o primeiro elemento do topo da pilha
int push(Pilha *p, int dado); //adiciona um elemento no topo da pilha
