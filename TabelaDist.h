#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

#ifndef TABELA_H
#define TABELA_H

// Tabela vertice-custo
//  Implementar com alguma forma de otimizacao para n precisar busca O(n)
//  Pode usar o id como chave de busca mas tem q colocar %tam
//  colocar lista dessa celula(vert-custo) em cada pos consequentmente
//  Ai qnd for buscar, vem e busca dentro dessa lista
typedef struct table Tabeladist;

Tabeladist *IniciaTabela(int tam);

void InsereVert(Tabeladist *alvo, Vertice *vertIns, double dist);

double GetDist(Tabeladist *alvo, Vertice *vertBus);

void ImprimeTabela(Tabeladist *alvo);

void LiberaTabela(Tabeladist *alvo);

#endif