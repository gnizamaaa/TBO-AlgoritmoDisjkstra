#include "Vertice.h"
#include "ListaVertice.h"
#include <stdio.h>
#include <stdlib.h>

struct vertice
{
    int id;
    ListaVertice *saidas;
};

Vertice *IniciaVertice(int ID, int tamMapa)
{
    Vertice *saida = malloc(sizeof(Vertice));
    saida->id = ID;
    saida->saidas = inicializaListaVertice(tamMapa);
    return saida;
}

void ConectaVertice(Vertice *orig, Vertice *dest, double dist)
{
    insereListaVertice(orig->saidas, dest, dist);
}

int GetID(Vertice *v)
{
    return v->id;
}

int IsConnected(Vertice *orig, Vertice *dest)
{
    if (getVert(orig->saidas, dest))
    {
        return 1;
    }
    else
        return 0;
}

void IteraAdj(Vertice *vert, PQ *fila, double custoVertAtual, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual))
{
    IteraLista(vert->saidas, fila, custoVertAtual, func);
}

void LiberaVertice(Vertice *v)
{
    liberaLista(v->saidas);
    free(v);
}
