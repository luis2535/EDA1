typedef struct horaminuto Horaminuto;
struct horaminuto
{
    int HORA;
    int MINUTO;
};
typedef struct time Tempo;
struct time
{
    int DIA;
    int MES;
    int ANO;
    Horaminuto *HORAS;
};
typedef struct reg Reg;
struct reg
{
    char NOME[30];
    Horaminuto *DURACAO;
    Tempo *DEADLINE;
};
typedef struct dados Tarefa;
struct dados
{
    int ID;
    Reg *DADOS;
    Tarefa *prox;
};
Horaminuto *criaHoraminuto(int hora, int minuto);
Tempo *criaTempo(int dia, int mes, int ano, Horaminuto *horas);
Reg *criaReg(char *nome, Horaminuto *duracao, Tempo *deadline);
Tarefa *criaTarefas(int id, Reg *dados);
Tarefa *insereTarefa(Tarefa *l, Tarefa *novo, int id);
void imprimeLista(Tarefa *l);
Tarefa *removerTarefa(Tarefa *l, int id);
Tarefa *encontraTarefa(Tarefa *l, int id);
Tarefa *editarTarefa(Tarefa *l);
void imprimeNome(Tarefa *l);