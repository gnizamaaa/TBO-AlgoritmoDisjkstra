#ifndef VERTICE_H
#define VERTICE_H
//#include "PQ.h"

typedef struct vertice Vertice;

/**
 * @brief Aloca memoria para um vertice
 *
 * @param ID
 * @param tamMapa
 * @return Vertice*
 */
Vertice *IniciaVertice(int ID, int tamMapa);

/**
 * @brief Faz uma aresta origem - destino com peso dist
 *
 * @param orig
 * @param dest
 * @param dist
 */
void ConectaVertice(Vertice *orig, Vertice *dest, double dist);

/**
 * @brief Obtem o ID do vertice
 *
 * @param v
 * @return int
 */
int GetID(Vertice *v);

/**
 * @brief Set o tipo do vertice para o char passado
 *
 * @param v
 * @param tipo
 */
void SetTipo(Vertice *v, char tipo);

/**
 * @brief Checa se eh Cliente
 *
 * @param v
 * @return int
 */
int IsCli(Vertice *v);

/**
 * @brief Checa se eh Servidor
 *
 * @param v
 * @return int
 */
int IsServ(Vertice *v);

/**
 * @brief Checa se eh Monitor
 *
 * @param v
 * @return int
 */
int IsMon(Vertice *v);

/**
 * @brief Checa se ha uma aresta partindo de origem para destino
 *
 * @param orig
 * @param dest
 * @return int
 */
int IsConnected(Vertice *orig, Vertice *dest);

typedef struct pq PQ;
/**
 * @brief Itera os vertices adjacentes (atraves da lista de adjacentes) executando a funcao passada com os
 * argumentos desejados
 *
 * @param vert
 * @param fila
 * @param custoVertAtual
 * @param func
 */
void IteraAdj(Vertice *vert, PQ *fila, double custoVertAtual, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual));

/**
 * @brief Libera a memoria alocada pelo vetor
 *
 * @param v
 */
void LiberaVertice(Vertice *v);

#endif