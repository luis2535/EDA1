typedef struct fib Fibonacci;
struct fib
{
    int dado;
    Fibonacci *prox;
};
Fibonacci *criaLSE(Fibonacci *l, int n);
Fibonacci *cria(int valor);
void imprime_lista(Fibonacci *l);
Fibonacci *inicializa();
int ehprimo(int n);
