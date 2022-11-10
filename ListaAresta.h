#ifndef LISTVERT_H
#define LISTVERT_H

#include "Aresta.h"

typedef struct listaAresta ListaAresta;

ListaAresta *InicializaListaAresta(int tam);

void InsereListaAresta(ListaAresta *list, Aresta *inserida);

void ListaSort(ListaAresta *list);

Aresta *GetAresta(ListaAresta *list, int Pos);

#endif