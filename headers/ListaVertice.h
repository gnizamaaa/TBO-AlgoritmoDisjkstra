#include "Vertice.h"
#include "PQ.h"

#ifndef LISTVERT_H
#define LISTVERT_H

/// @brief Linked-List de Vertices com o peso
typedef struct listaVertice ListaVertice;

/**
 * @brief Aloca memoria para uma lista (uma sentinela)
 *
 * @param tam
 * @return ListaVertice*
 */
ListaVertice *inicializaListaVertice(int tam);

/**
 * @brief Insere um vertice na lista, preenchendo o custo para esse vertice como o fornecido
 *
 * @param list
 * @param inserida
 * @param custo
 */
void insereListaVertice(ListaVertice *list, Vertice *inserida, double custo);

/**
 * @brief Obtem o vertice caso a lista tenha o vertice, retornando NULL caso nao esteja na lista
 * 
 * @param list 
 * @param buscado 
 * @return Vertice* 
 */
Vertice *getVert(ListaVertice *list, Vertice *buscado);

/**
 * @brief Obtem o custo associado ao vertice, caso o vertice nao esteja na lista, retorna-se -1
 * 
 * @param list 
 * @param buscado 
 * @return double 
 */
double getCusto(ListaVertice *list, Vertice *buscado);

/**
 * @brief Itera a lista de vertices executando a funcao passada com os argumentos desejados 
 * 
 * @param list 
 * @param fila 
 * @param custoVertAtualvoid 
 * @param func 
 */
void IteraLista(ListaVertice *list, PQ *fila, double custoVertAtualvoid, void func(Vertice *vert, double custo, PQ *fila, double custoVertAtual));

/**
 * @brief Libera a memoria alocada pela lista e suas celulas
 * 
 * @param list 
 */
void liberaLista(ListaVertice *list);
#endif