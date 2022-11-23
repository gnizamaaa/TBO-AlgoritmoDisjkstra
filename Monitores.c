#include "Vertice.h"
#include "TabelaDist.h"
#include "ListaVertice.h"
#include "Monitores.h"
#include "PQ.h"

struct monitor
{
    Vertice *vert;
    // Distancia para cada servidor
    Tabeladist *RTTServ;
};

Monitor *IniciaMonitor(Vertice *vert, int qtdServ)
{
    Monitor *saida = malloc(sizeof(Monitor));
    saida->vert = vert;
    saida->RTTServ = IniciaTabela(qtdServ);
    return saida;
}

Vertice *GetVerticeMon(Monitor *mon)
{
    return mon->vert;
}

// Insere o vertice pego com o getVertice do obj a ser inserido
void InsereArestaMon(Monitor *alvo, Vertice *vertIns, double dist)
{
    // insereListaVertice(, vertIns, dist);
    ConectaVertice(alvo->vert, vertIns, dist);
}

void Atualizafila(Vertice *vert, double custo, PQ *fila, double custoVertAtual)
{
    if (PQ_get_key(fila, GetID(vert)) > custo + custoVertAtual)
    {
        PQ_decrease_key(fila, GetID(vert), custo + custoVertAtual);
    }
}

int IsServ(Vertice **vetServ, int qtdServ, Vertice *removido)
{
    for (int i = 0; i < qtdServ; i++)
    {
        if (vetServ[i] == removido)
            return 1;
    }
    return 0;
}

// Aplica Disjkstra nele - Talvez precise passar a lista com os todos os vertices
void CalculaDistsMon_Serv(Monitor *mon, Vertice **vetServ, int qtdServ, Vertice **todos, int total)
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
        if (IsServ(vetServ, qtdServ, removido))
            InsereVert(mon->RTTServ, removido, custo);
    }
    PQ_finish(fila);
}

// Busca na tabela
double Dist_MonServ(Monitor *mon, Vertice *sev)
{
    return GetDist(mon->RTTServ, sev);
}

// Retorna a tabela
Tabeladist *getTabela_MonServ(Monitor *mon)
{
    return mon->RTTServ;
}

void LiberaMonitor(Monitor *alvo)
{
    LiberaTabela(alvo->RTTServ);
    // LiberaVertice(alvo->vert);
    free(alvo);
}