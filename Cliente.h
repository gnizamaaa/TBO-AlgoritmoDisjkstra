// TODO: Cliente
#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"
#include "Monitores.h"
#include "Servidor.h"
#include "TabelaDist.h"

#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente Cliente;

Cliente *IniciaCliente(Vertice *vert, int qtdServ);

Vertice *GetVerticeCli(Cliente *mon);

// Insere o vertice pego com o getVertice do obj a ser inserido
void InsereAresta(Cliente *alvo, Vertice *vertIns, double dist);

void CalculaDistsCli_Serv(Cliente *cli, Servidor **vetServ, int qtdServ, Monitor **vetMon, int qtdMon, Vertice **todos, int total);

// Retorna a tabela
Tabeladist *getTabela_RTTReal(Cliente *cli);
Tabeladist *getTabela_RTTFake(Cliente *cli);

double getRTTReal(Cliente *cli, Vertice *buscado);
double getRTTFake(Cliente *cli, Vertice *buscado);

void LiberaCliente(Cliente *alvo);

#endif