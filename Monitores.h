#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"
#include "Servidor.h"
#include "TabelaDist.h"

#ifndef MONITOR_H
#define MONITOR_H

typedef struct monitor Monitor;

/**
 * @brief Aloca memoria para um Monitor
 *
 * @param vert
 * @param qtdServ
 * @param qtdCli
 * @return Monitor*
 */
Monitor *IniciaMonitor(Vertice *vert, int qtdServ, int qtdCli);

/**
 * @brief Obtem o vertice de um Monitor
 *
 * @param mon
 * @return Vertice*
 */
Vertice *GetVerticeMon(Monitor *mon);

/**
 * @brief Faz uma aresta partindo do monitor para o destino (vertIns) com peso dist
 *
 * @param alvo
 * @param vertIns
 * @param dist
 */
void InsereArestaMon(Monitor *alvo, Vertice *vertIns, double dist);

/**
 * @brief Faz os calculos necessarios para obter a distancia para todos os clientes e RTT para os servidores do grafo
 * partindo do monitor dado
 *
 * @param mon
 * @param vetServ
 * @param qtdServ
 * @param todos
 * @param total
 */
void CalculaDistsMon_Serv(Monitor *mon, Servidor **vetServ, int qtdServ, Vertice **todos, int total);

// Busca na tabela
/**
 * @brief Obtem o RTT para o vertice de servidor (vertice do servidor)
 *
 * @param mon
 * @param sev
 * @return double
 */
double Dist_MonServ(Monitor *mon, Vertice *sev);

/**
 * @brief Obtem a distancia (de ida) para o cliente (vertice do cliente)
 *
 * @param mon
 * @param dest
 * @return double
 */
double Dist_MonCli(Monitor *mon, Vertice *dest);

// Retorna a tabela
/**
 * @brief Retorna a tabela com o RTT para os servidores
 *
 * @param mon
 * @return Tabeladist*
 */
Tabeladist *getTabela_MonServ(Monitor *mon);

/**
 * @brief Retorna a tabela com a distancia para os clientes
 *
 * @param mon
 * @return Tabeladist*
 */
Tabeladist *getTabela_MonCli(Monitor *mon);

/**
 * @brief Libera a memoria alocada pelo monitor
 * 
 * @param alvo 
 */
void LiberaMonitor(Monitor *alvo);

#endif