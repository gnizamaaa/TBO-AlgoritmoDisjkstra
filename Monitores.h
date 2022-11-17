#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"
#include "Servidor.h"
#include "TabelaDist.h"

#ifndef MONITOR_H
#define MONITOR_H


typedef struct monitor Monitor;

Monitor *IniciaMonitor(int ID, int tamMapa);

Vertice* GetVerticeMon(Monitor* mon);

//Insere o vertice pego com o getVertice do obj a ser inserido
void InsereAresta(Monitor *alvo, Vertice *vertIns, double dist);

void CalculaDistsMon_Serv(Monitor* mon, Servidor**vetServ, int tam);

//Busca na tabela 
double Dist_MonServ(Monitor* mon, Servidor*sev);

//Retorna a tabela
Tabeladist* getTabela_MonServ(Monitor* mon);

void LiberaMonitor(Monitor *alvo);

#endif