#include "Vertice.h"

#ifndef Aresta_H
#define Aresta_H

typedef struct Aresta Aresta;

Aresta *InicializaAresta(Vertice *orig, Vertice *dest, double dist);

float GetDist(Aresta *Aresta);

int GetOrigem(Aresta *Aresta);

int GetDest(Aresta *Aresta);

int CmpAresta(const void *a1, const void *a2);

void DestroiAresta(Aresta *a1);

#endif