#include "ListaVertice.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;

struct celula
{
    Vertice *obj;
    double custo;
};

int CompareCel(const void *p1, const void *p2)
{
    const Celula *c1 = p1;
    const Celula *c2 = p2;
    if ((c1->custo - c2->custo) > 0)
        return 1;
    else if ((c1->custo - c2->custo) < 0)
        return -1;
    else
        return 0;
}

struct listaVertice
{
    Celula *vet;
    int tam;
    int max;
};

ListaVertice *inicializaListaVertice(int tam)
{
    ListaVertice *saida = malloc(sizeof(ListaVertice));
    saida->vet = malloc(sizeof(Celula) * tam);
    saida->tam = 0;
    saida->max = tam;
    return saida;
}

void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo)
{
    list->vet[list->tam].obj = inserida;
    list->vet[list->tam].custo = custo;
    list->tam++;
}

void listaSort(ListaVertice *list)
{
    qsort(list->vet, list->tam, sizeof(Celula), CompareCel);
}

Vertice *getVert(ListaVertice *list, Vertice *buscado)
{
    Vertice *saida = NULL;
    for (int i = 0; i < list->tam; i++)
    {
        if (list->vet[i].obj == buscado)
        {
            saida = buscado;
            break;
        }
    }
    return saida;
}

Vertice *getVertPos(ListaVertice *list, int Pos)
{
    if (Pos < list->tam)
        return list->vet[Pos].obj;
}

double getCusto(ListaVertice *list, Vertice *buscado)
{
    double saida = -1.0;
    for (int i = 0; i < list->tam; i++)
    {
        if (list->vet[i].obj == buscado)
        {
            saida = list->vet[i].custo;
            break;
        }
    }
    return saida;
}

double getCustoPos(ListaVertice *list, int Pos)
{
    if (Pos < list->tam)
        return list->vet[Pos].custo;
}

void IteraLista(ListaVertice *list, PQ *fila, double custoVertAtualvoid, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual))
{
    for (int i = 0; i < list->tam; i++)
    {
        func(list->vet[i].obj, list->vet[i].custo, fila, custoVertAtualvoid);
    }
}

void liberaLista(ListaVertice *list)
{
    // for (int i = 0; i < list->max; i++)
    // {
    //     free(list->vet[i]);
    // }
    free(list->vet); // n sei se precisa desse
    free(list);
}