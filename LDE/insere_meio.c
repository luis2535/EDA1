nodo *insere_meio(nodo *lista, int valor)
{
    nodo *novo, a, p;
    novo = nodo * cria_nodo(valor);
    p = lista;
    a = NULL;
    while (p != NULL && p->dado < valor)
    {
        a = p;
        p = p->prox;
    }
    if (a == NULL)
    {
        novo->prox = p;
        novo->ant = a;
        p->ant = novo;
        return (lista);
    }
    if (p == NULL)
    {
        novo->ant = a;
        a->prox = novo;
        return (lista);
    }
    novo->ant = a;
    a->prox = novo;
    novo->prox = p;
    p->ant = novo;
    return (lista);
}