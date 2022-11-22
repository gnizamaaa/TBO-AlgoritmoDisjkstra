#ifndef ITEM_H
#define ITEM_H
#include "Vertice.h"

typedef struct
{
  Vertice *vert; // identificador do nó
  double value;  // valor associado ao nó
} Item;

#define id(A) (GetID(A.vert))           // retorna identificador do nó
#define value(A) (A.value)               // retorna valor do nó
#define more(A, B) (value(A) > value(B)) // compara nós, por valor
#define exch(A, B) \
  {                \
    Item t = A;    \
    A = B;         \
    B = t;         \
  } // troca dois nós

#endif
