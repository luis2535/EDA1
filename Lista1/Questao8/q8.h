typedef struct reg polinomio;
struct reg
{
    int coeficiente;
    int expoente;
    polinomio *prox;
};
polinomio *inicializa();                                        //funcao inicializa a struct com um NULL
polinomio *cria_nodo(int coeficiente, int expoente);            // funcao recebe um coeficiente e um expoente, alocara memoria e resultara em um nodo
polinomio *insere_ordenado(polinomio *lista, polinomio *novo);  //funcao recebe uma lista e um nodo e insere de maneira ordenada com base no expoente o nodo na lista
polinomio *concatena(polinomio *lista1, polinomio *lista2);     //funcao deve receber 2 listas, a segunda lista sera concatenada ao final da primeira
polinomio *somaPolinomio(polinomio *lista1, polinomio *lista2); //funcao recebera 2 lse, representando os 2 polinomios e fara as somas comparando seus expoentes
void imprime_polinomio(polinomio *lista);                       //funcao recebera um lse que representa os polinomios e fara a impressao no formato (coeficiente)X(expoente)