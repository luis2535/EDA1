typedef struct registro Aluno;
struct registro
{
    int matricula;
    char nome[50];
    float notas[3];
};
typedef struct reg nodo;
struct reg
{
    Aluno *aluno;
    nodo *prox;
    nodo *ant;
};

nodo *inicializa();
nodo *criaAluno();
nodo *inserir_fim(nodo *lista, nodo *novo);
void imprime_lista(nodo *lista);
float calcular_mediana(nodo *l);