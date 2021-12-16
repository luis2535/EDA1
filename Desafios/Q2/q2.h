typedef struct Sobrenome sobrenome;

struct Sobrenome
{
    char letra;
    sobrenome *prox;
};
sobrenome *insere_fim(sobrenome *nome, char *letra);
int eFacil(sobrenome *l);