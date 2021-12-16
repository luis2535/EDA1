typedef struct reg polinomio;
struct reg
{
    int coeficiente;
    polinomio *prox;
};

polinomio *inicializa();                              //funcao inicializa a struct com um NULL
polinomio *cria_nodo(int coeficiente);                // funcao recebe um coeficiente, alocara memoria e resultara em um nodo
polinomio *insere_fim(polinomio *l, polinomio *novo); // funcao recebera uma lse e um nodo e ira inserir o nodo ao fim da lista
void imprime_lista(polinomio *l);                     // funcao recebe a lista, chama a funcao conta_nos para ver os expoentes de cada coeficiente e imprime o polinomio
int conta_nos(polinomio *l);                          //funcao recebe uma lista e itera todas as suas posicoes somadno 1 em um contador, ao final retorna esse contador
float calcular(polinomio *p, float x);                //funcao recebe a lista de polinomios e um float x, que representa o valor de x, e fara um calculo de seu valor