typedef struct reg nodo;
struct reg
{
    int dado;
    nodo *prox;
    nodo *ant;
};
nodo *inicializa();
nodo *inserir_fim(nodo *lista, int valor);
nodo *inserir_inicio(nodo *lista, int valor);
nodo *insere_ordenado(nodo *lista, int valor);
void imprime_lista(nodo *lista);
int busca_posicao(nodo *lista, int valor);
nodo *altera_valor(nodo *lista, int valor);
nodo *remove_valor(nodo *lista, int valor);
nodo *troca(nodo *lista, int valor);                 //funcao deve receber uma lde e um valor, esse valor sera procurado na lista e seu valor sera invertido com seu sucessor
nodo *trocaNos(nodo *lista, int valor1, int valor2); //funcao deve receber uma lde e 2 valores, os nodos referentes a esses valores serao procurados na lista e suas posicoes trocadas