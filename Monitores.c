#include "Vertice.h"
#include "TabelaDist.h"
#include "ListaVertice.h"
#include "Monitores.h"
#include "PQ.h"

struct monitor
{
    Vertice *vert;
    // RTT para cada servidor
    Tabeladist *RTTServ;
    // Distancia para cada cliente
    Tabeladist *SaidaCli;
};

Monitor *IniciaMonitor(Vertice *vert, int qtdServ, int qtdCli)
{
    Monitor *saida = malloc(sizeof(Monitor));
    saida->vert = vert;
    saida->RTTServ = IniciaTabela(qtdServ);
    saida->SaidaCli = IniciaTabela(qtdCli);
    return saida;
}

Vertice *GetVerticeMon(Monitor *mon)
{
    return mon->vert;
}

void InsereArestaMon(Monitor *alvo, Vertice *vertIns, double dist)
{
    ConectaVertice(alvo->vert, vertIns, dist);
}

/**
 * @brief Atualiza a Priority Queue com os valores (possivelmente menores)
 * de custo obtidos através dos vertices adjacentes ao retirado da fila
 * 
 * @param vert 
 * @param custo 
 * @param fila 
 * @param custoVertAtual 
 */
static void Atualizafila(Vertice *vert, double custo, PQ *fila, double custoVertAtual)
{
    if (PQ_get_key(fila, GetID(vert)) > custo + custoVertAtual)
    {
        PQ_decrease_key(fila, GetID(vert), custo + custoVertAtual);
    }
}

// Aplica Disjkstra nele - Talvez precise passar a lista com os todos os vertices
void CalculaDistsMon_Serv(Monitor *mon, Servidor **vetServ, int qtdServ, Vertice **todos, int total)
{
    PQ *fila = PQ_init(total);
    for (int i = 0; i < total; i++)
    {
        // Inicia tds como infinito
        PQ_insert(fila, todos[i], 9999999999);
    }
    // A origem como 0
    PQ_decrease_key(fila, GetID(mon->vert), 0);

    while (!PQ_empty(fila))
    {
        // Pega a menor chave, remove da fila e atualiza a fila
        double custo = PQ_get_key(fila, GetID(PQ_min(fila)));
        Vertice *removido = PQ_delmin(fila);
        IteraAdj(removido, fila, custo, Atualizafila);
        // Se eh um servidor, insere na tabela o custo
        if (IsServ(removido))
        {
            Servidor *dest = NULL;
            for (int i = 0; i < qtdServ; i++)
            {
                if (GetVerticeServ(vetServ[i]) == removido)
                {
                    dest = vetServ[i];
                    break;
                }
            }
            InsereVert(mon->RTTServ, removido, (custo + DistIda(dest, mon->vert)));
        }
        else if (IsCli(removido))
        {
            InsereVert(mon->SaidaCli, removido, custo);
        }
    }
    PQ_finish(fila);
}

// Busca na tabela
double Dist_MonServ(Monitor *mon, Vertice *sev)
{
    return GetDist(mon->RTTServ, sev);
}

double Dist_MonCli(Monitor *mon, Vertice *dest)
{
    return GetDist(mon->SaidaCli, dest);
}

// Retorna a tabela
Tabeladist *getTabela_MonServ(Monitor *mon)
{
    return mon->RTTServ;
}

Tabeladist *getTabela_MonCli(Monitor *mon)
{
    return mon->SaidaCli;
}

void LiberaMonitor(Monitor *alvo)
{
    LiberaTabela(alvo->RTTServ);
    LiberaTabela(alvo->SaidaCli);
    // LiberaVertice(alvo->vert);
    free(alvo);
}