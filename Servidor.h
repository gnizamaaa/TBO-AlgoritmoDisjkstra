#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H


typedef struct servidor Servidor;

Servidor *IniciaServidor(int ID, int tamMapa);

Vertice* GetVerticeMon(Servidor* mon);

void InsereAresta(Servidor *alvo, Vertice *vertIns, double dist);

void LiberaServidor(Servidor *alvo);

#endif