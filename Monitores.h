#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"
#include "Servidor.h"
#include "TabelaDist.h"

#ifndef MONITOR_H
#define MONITOR_H

typedef struct monitor Monitor;

Monitor *IniciaMonitor(Vertice *vert, int qtdServ);

Vertice *GetVerticeMon(Monitor *mon);

// Insere o vertice pego com o getVertice do obj a ser inserido
void InsereArestaMon(Monitor *alvo, Vertice *vertIns, double dist);

void CalculaDistsMon_Serv(Monitor *mon, Vertice **vetServ, int qtdServ, Vertice **todos, int total);

// Busca na tabela
double Dist_MonServ(Monitor *mon, Vertice *sev);

// Retorna a tabela
Tabeladist *getTabela_MonServ(Monitor *mon);

void LiberaMonitor(Monitor *alvo);

#endif