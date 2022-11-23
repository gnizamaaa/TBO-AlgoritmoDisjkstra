#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H

typedef struct servidor Servidor;

Servidor *IniciaServidor(Vertice *vert, int qtdServ);

int GetIDServ(Servidor *ser);

double DistIda(Servidor *ser, Vertice *dest);

Vertice *GetVerticeServ(Servidor *ser);

void CalculaSaidaServ(Servidor *ser, Vertice **todos, int qtd);

void LiberaServidor(Servidor *alvo);

#endif