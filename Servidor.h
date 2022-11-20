#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H

typedef struct servidor Servidor;

Servidor *IniciaServidor(Vertice *vert, int qtdServ);

int GetIDServ(Servidor *ser);

Vertice *GetVerticeServ(Servidor *ser);

void InsereArestaServ(Servidor *alvo, Vertice *vertIns, double dist);

void LiberaServidor(Servidor *alvo);

#endif