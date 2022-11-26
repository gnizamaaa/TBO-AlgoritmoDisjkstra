#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H

typedef struct servidor Servidor;

/**
 * @brief Aloca memoria para um Servidor
 *
 * @param vert
 * @param tamTotal
 * @return Servidor*
 */
Servidor *IniciaServidor(Vertice *vert, int tamTotal);

/**
 * @brief Obtem o ID do Servidor
 *
 * @param ser
 * @return int
 */
int GetIDServ(Servidor *ser);

/**
 * @brief Obtem o Vertice do Servidor
 *
 * @param ser
 * @return Vertice*
 */
Vertice *GetVerticeServ(Servidor *ser);

/**
 * @brief Obtem a distancia do servidor ao vertice
 *
 * @param ser - Servidor com distancias calculadas (pela funcao CalculaSaidaServ)
 * @param dest
 * @return double
 */
double DistIda(Servidor *ser, Vertice *dest);

/**
 * @brief Faz os calculos necessarios para obter a distancia para todos os vertices do grafo
 * partindo do servidor dado
 *
 * @param ser
 * @param todos - Vetor com todos os vertices do grafo
 * @param qtd - Tamanho do vetor com todos vertices do grafo
 */
void CalculaSaidaServ(Servidor *ser, Vertice **todos, int qtd);

/**
 * @brief Libera a memoria alocada pelo Servidor
 * (sem liberar o vertice fornecido para a criacao)
 *
 * @param alvo
 */
void LiberaServidor(Servidor *alvo);

#endif