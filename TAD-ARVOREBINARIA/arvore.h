typedef struct reg nodo;
struct reg
{
    int chave;
    int conteudo;
    nodo *esq;
    nodo *dir;
};
typedef nodo *arvore;
nodo *cria_no(int chave);
arvore insere(arvore r, nodo *novo);
nodo *busca(arvore r, int chave);
