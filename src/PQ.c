#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "Vertice.h"

struct pq
{
    Item *vet; // Vet de itens
    int *map;  // ID dos itens - esta separado para maior facilidade
    int N;
};

static void swap(PQ *base, int i, int j)
{
    exch(base->vet[i], base->vet[j]);
    base->map[id(base->vet[i])] = i;
    base->map[id(base->vet[j])] = j;
}

void fix_up(PQ *base, Item *a, int k)
{
    while (k > 1 && more(a[k / 2], a[k]))
    {
        swap(base, k, k / 2);
        k = k / 2;
    }
}

void fix_down(PQ *base, Item *a, int sz, int k)
{
    while (2 * k <= sz)
    {
        int j = 2 * k;
        if (j < sz && more(a[j], a[j + 1]))
        {
            j++;
        }
        if (!more(a[k], a[j]))
        {
            break;
        }
        swap(base, k, j);
        k = j;
    }
}

PQ *PQ_init(int maxN)
{
    PQ *saida = malloc(sizeof(PQ));
    saida->vet = (Item *)malloc((maxN+2) * sizeof(Item));
    saida->map = (int *)malloc((maxN+2) * sizeof(int));
    saida->N = 0;
    return saida;
}

void PQ_insert(PQ *base, Vertice *vert, double dist)
{
    base->N++;
    base->vet[base->N].value = dist;
    base->vet[base->N].vert = vert;
    base->map[GetID(vert)] = base->N;
    fix_up(base, base->vet, base->N);
}

Vertice *PQ_delmin(PQ *base)
{
    if (base->N > 0)
    {
        Item min = base->vet[1];

        swap(base, 1, base->N);
        base->N--;
        fix_down(base, base->vet, base->N, 1);

        return min.vert;
    }
    else
        return NULL;
}

Vertice *PQ_min(PQ *base)
{
    return base->vet[1].vert;
}

void PQ_decrease_key(PQ *base, int id, double value)
{
    int i = base->map[id];
    value(base->vet[i]) = value;
    fix_up(base, base->vet, i);
}

double PQ_get_key(PQ *base, int id)
{
    int i = base->map[id];
    return base->vet[i].value;
}

bool PQ_empty(PQ *base)
{
    return base->N == 0;
}

int PQ_size(PQ *base)
{
    return base->N;
}

void PQ_finish(PQ *base)
{
    free(base->vet);
    free(base->map);
    free(base);
}
