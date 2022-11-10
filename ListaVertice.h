#include "Vertice.h"

#ifndef LISTVERT_H
#define LISTVERT_H

typedef struct listaVertice ListaVertice;

ListaVertice *inicializaListaVertice(int tam);

void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo);

void listaSort(ListaVertice *list);

Vertice *getVert(ListaVertice *list, Vertice *buscado);

Vertice *getVertPos(ListaVertice *list, int Pos);

void liberaLista(ListaVertice *list);
#endif