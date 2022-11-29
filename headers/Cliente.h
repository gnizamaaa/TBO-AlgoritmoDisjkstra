#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"
#include "Monitores.h"
#include "Servidor.h"
#include "TabelaDist.h"

#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente Cliente;

/**
 * @brief Aloca memoria para um Cliente
 *
 * @param vert
 * @param qtdServ
 * @return Cliente*
 */
Cliente *IniciaCliente(Vertice *vert, int qtdServ);

/**
 * @brief Obtem o vertice de um Cliente
 *
 * @param mon
 * @return Vertice*
 */
Vertice *GetVerticeCli(Cliente *mon);

/**
 * @brief Faz uma aresta partindo do cliente para o destino (vertIns) com peso dist
 *
 * @param alvo
 * @param vertIns
 * @param dist
 */
void InsereAresta(Cliente *alvo, Vertice *vertIns, double dist);

/**
 * @brief Faz os calculos necessarios para obter o RTT para todos os servidores do grafo
 * partindo do servidor dado
 *
 * @param cli
 * @param vetServ - Vetor com todos os servidores do grafo
 * @param qtdServ - Tamanho do vetor com todos servidores do grafo
 * @param vetMon - Vetor com todos os monitores do grafo
 * @param qtdMon - Tamanho do vetor com todos monitores do grafo
 * @param todos - Vetor com todos os vertices do grafo
 * @param total - Tamanho do vetor com todos vertices do grafo
 */
void CalculaDistsCli_Serv(Cliente *cli, Servidor **vetServ, int qtdServ, Monitor **vetMon, int qtdMon, Vertice **todos, int total);

// Retorna a tabela
/**
 * @brief Retorna a tabela com o RTT real para os servidores
 *
 * @param cli
 * @return Tabeladist*
 */
Tabeladist *getTabela_RTTReal(Cliente *cli);

/**
 * @brief Retorna a tabela com o RTT falso para os servidores
 *
 * @param cli
 * @return Tabeladist*
 */
Tabeladist *getTabela_RTTFake(Cliente *cli);

/**
 * @brief Obtem o RTT real do cliente ao servidor
 *
 * @param cli
 * @param buscado - Vertice de um servidor
 * @return double
 */
double getRTTReal(Cliente *cli, Vertice *buscado);

/**
 * @brief Obtem o RTT falso do cliente ao servidor
 *
 * @param cli
 * @param buscado - Vertice de um servidor
 * @return double
 */
double getRTTFake(Cliente *cli, Vertice *buscado);

/**
 * @brief Libera a memoria alocada pelo cliente
 * (sem liberar o vertice fornecido para a criacao)
 *
 * @param alvo
 */
void LiberaCliente(Cliente *alvo);

#endif