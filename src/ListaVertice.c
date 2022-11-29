#include "ListaVertice.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;

struct celula
{
    Vertice *obj;
    double custo;
    Celula *prox;
};

/**
 * @brief Comparador de celulas
 * 
 * @param p1 
 * @param p2 
 * @return int 
 */
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
    Celula *ini;
    Celula *ult;
    int tam;
};

ListaVertice *inicializaListaVertice(int tam)
{
    ListaVertice *saida = malloc(sizeof(ListaVertice));
    saida->ini = NULL;
    saida->ult = NULL;
    saida->tam = 0;
    return saida;
}

void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo)
{
    Celula *insertCel = (Celula *)malloc(sizeof(Celula));
    insertCel->custo = custo;
    insertCel->obj = inserida;
    insertCel->prox = NULL;

    if (list->ini == NULL)
    {
        list->ini = insertCel;
    }
    else
    {
        list->ult->prox = insertCel;
    }
    list->ult = insertCel;
}

Vertice *getVert(ListaVertice *list, Vertice *buscado)
{
    if (list->ini == NULL)
    {
        return NULL;
    }

    Celula *aux = list->ini;

    while (aux != NULL)
    {
        if (aux->obj == buscado)
        {
            return aux->obj;
        }
        aux = aux->prox;
    }

    return NULL;
}

double getCusto(ListaVertice *list, Vertice *buscado)
{
    if (list->ini == NULL)
    {
        return -1;
    }

    Celula *aux = list->ini;

    while (aux != NULL)
    {
        if (aux->obj == buscado)
        {
            return aux->custo;
        }
        aux = aux->prox;
    }

    return -1;
}

void IteraLista(ListaVertice *list, PQ *fila, double custoVertAtualvoid, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual))
{
    if (list->ini == NULL)
    {
        return;
    }

    Celula *aux = list->ini;

    while (aux != NULL)
    {
        func(aux->obj, aux->custo, fila, custoVertAtualvoid);
        aux = aux->prox;
    }

    return;
}
void liberaLista(ListaVertice *list)
{
    Celula *aux = list->ini;
    while (aux != NULL)
    {
        list->ini = aux->prox;
        free(aux);
        aux = list->ini;
    }
    free(list);
}

// void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo)
// {
//     list->vet[list->tam].obj = inserida;
//     list->vet[list->tam].custo = custo;
//     list->tam++;
// }

// void listaSort(ListaVertice *list)
// {
//     qsort(list->vet, list->tam, sizeof(Celula), CompareCel);
// }

// Vertice *getVert(ListaVertice *list, Vertice *buscado)
// {
//     Vertice *saida = NULL;
//     for (int i = 0; i < list->tam; i++)
//     {
//         if (list->vet[i].obj == buscado)
//         {
//             saida = buscado;
//             break;
//         }
//     }
//     return saida;
// }

// Vertice *getVertPos(ListaVertice *list, int Pos)
// {
//     if (Pos < list->tam)
//         return list->vet[Pos].obj;
// }

// double getCusto(ListaVertice *list, Vertice *buscado)
// {
//     double saida = -1.0;
//     for (int i = 0; i < list->tam; i++)
//     {
//         if (list->vet[i].obj == buscado)
//         {
//             saida = list->vet[i].custo;
//             break;
//         }
//     }
//     return saida;
// }

// double getCustoPos(ListaVertice *list, int Pos)
// {
//     if (Pos < list->tam)
//         return list->vet[Pos].custo;
// }

// void IteraLista(ListaVertice *list, PQ *fila, double custoVertAtualvoid, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual))
// {
//     for (int i = 0; i < list->tam; i++)
//     {
//         func(list->vet[i].obj, list->vet[i].custo, fila, custoVertAtualvoid);
//     }
// }

// void liberaLista(ListaVertice *list)
// {
//     // for (int i = 0; i < list->max; i++)
//     // {
//     //     free(list->vet[i]);
//     // }
//     free(list->vet); // n sei se precisa desse
//     free(list);
// }