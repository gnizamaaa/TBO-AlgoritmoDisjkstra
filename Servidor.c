#include "Vertice.h"
#include "TabelaDist.h"
#include "Servidor.h"
#include "PQ.h"

struct servidor
{
    Vertice *vert;
    Tabeladist *DistIda;
};

Servidor *IniciaServidor(Vertice *vert, int tamTotal)
{
    Servidor *saida = malloc(sizeof(Servidor));
    saida->DistIda = IniciaTabela(tamTotal);
    saida->vert = vert;
    return saida;
}

int GetIDServ(Servidor *ser)
{
    return GetID(ser->vert);
}

Vertice *GetVerticeServ(Servidor *ser)
{
    return ser->vert;
}

double DistIda(Servidor *ser, Vertice *dest)
{
    return GetDist(ser->DistIda, dest);
}

/**
 * @brief Atualiza a Priority Queue com os valores (possivelmente menores)
 * de custo obtidos através dos vertices adjacentes ao retirado da fila
 *
 * @param vert - Vertice adjacente 
 * @param custo - Custo do vertice retirado para o adjacente
 * @param fila - PQ
 * @param custoVertAtual - Custo da origem ao vertice retirado
 */
static void Atualizafila(Vertice *vert, double custo, PQ *fila, double custoVertAtual)
{
    if (PQ_get_key(fila, GetID(vert)) > custo + custoVertAtual)
    {
        PQ_decrease_key(fila, GetID(vert), custo + custoVertAtual);
    }
}

void CalculaSaidaServ(Servidor *ser, Vertice **todos, int qtd)
{
    PQ *fila = PQ_init(qtd);
    for (int i = 0; i < qtd; i++)
    {
        // Inicia tds como infinito
        PQ_insert(fila, todos[i], 9999999999);
    }
    // A origem como 0
    PQ_decrease_key(fila, GetID(ser->vert), 0);

    while (!PQ_empty(fila))
    {
        // Pega a menor chave, remove da fila e atualiza a fila
        double custo = PQ_get_key(fila, GetID(PQ_min(fila)));
        Vertice *removido = PQ_delmin(fila);
        IteraAdj(removido, fila, custo, Atualizafila);
        InsereVert(ser->DistIda, removido, custo);
    }
    PQ_finish(fila);

    // printf("\nServidor \n");
    // ImprimeTabela(ser->DistIda);
}

void LiberaServidor(Servidor *alvo)
{
    LiberaTabela(alvo->DistIda);
    free(alvo);
}
