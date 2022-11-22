#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"
#include "Vertice.h"

typedef struct pq PQ;

PQ *PQ_init(int maxN);                                // cria uma min PQ com capacidade maxN
void PQ_insert(PQ *base, Vertice *vert, double dist); // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Vertice *PQ_delmin(PQ *base);                         // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(PQ *base, int id, double value); // Muda a prioridade do nó com identificador 'id' para 'value'
double PQ_get_key(PQ *base, int id);                  //
Vertice *PQ_min(PQ *base);                            // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(PQ *base);                              // Retorna True se a PQ não tem elementos
int PQ_size(PQ *base);                                // Número de elementos na PQ
void PQ_finish(PQ *base);                             // Libera memória

#endif
