#include "Vertice.h"
#include "PQ.h"

#ifndef LISTVERT_H
#define LISTVERT_H

/// @brief Array-list de Vertices com o peso
typedef struct listaVertice ListaVertice;

ListaVertice *inicializaListaVertice(int tam);

void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo);

void listaSort(ListaVertice *list);

Vertice *getVert(ListaVertice *list, Vertice *buscado);

Vertice *getVertPos(ListaVertice *list, int Pos);

double getCusto(ListaVertice *list, Vertice *buscado);

double getCustoPos(ListaVertice *list, int Pos);

void IteraLista(ListaVertice *list, PQ *fila, double custoVertAtualvoid, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual));
void liberaLista(ListaVertice *list);
#endif