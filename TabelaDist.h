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
typedef struct tabela Tabeladist;

/**
 * @brief Aloca a memoria necessaria para armazenar a tabela
 * 
 * @param tam - TamMax de elementos da tabela
 * @return Tabeladist* 
 */
Tabeladist *IniciaTabela(int tam);

/**
 * @brief Insere um Vertice na tabela
 * 
 * @param alvo - Tabela a ser inserida
 * @param vertIns - Vertice
 * @param dist - Custo relacionado a esse vertice
 */
void InsereVert(Tabeladist *alvo, Vertice *vertIns, double dist);

/**
 * @brief Obtem o custo relacionado a um dado vertice
 * 
 * @param alvo - Tabela de consulta
 * @param vertBus - Vertice 
 * @return double - Custo relacionado a esse vertice
 */
double GetDist(Tabeladist *alvo, Vertice *vertBus);

/**
 * @brief Imprime a tabela com o formato ID(Vertice) - Custo
 * 
 * @param alvo 
 */
void ImprimeTabela(Tabeladist *alvo);

/**
 * @brief Libera a memoria alocada pela tabela
 * 
 * @param alvo 
 */
void LiberaTabela(Tabeladist *alvo);

#endif