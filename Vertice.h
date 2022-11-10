#ifndef VERTICE_H
#define VERTICE_H

typedef struct vertice Vertice;

Vertice *IniciaVertice(int ID, int tamMapa);

void ConectaVertice(Vertice *orig, Vertice *dest, double dist);

int GetID(Vertice *v);

int IsConnected(Vertice *orig, Vertice *dest);

void LiberaVertice(Vertice *v);

#endif