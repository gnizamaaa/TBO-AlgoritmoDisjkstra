#ifndef VERTICE_H
#define VERTICE_H
//#include "PQ.h"

typedef struct vertice Vertice;

Vertice *IniciaVertice(int ID, int tamMapa);

void ConectaVertice(Vertice *orig, Vertice *dest, double dist);

int GetID(Vertice *v);

int IsConnected(Vertice *orig, Vertice *dest);

typedef struct pq PQ;
void IteraAdj(Vertice *vert, PQ *fila, double custoVertAtual, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual));

void LiberaVertice(Vertice *v);

#endif