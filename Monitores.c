#include "Vertice.h"
#include "TabelaDist.h"
#include "ListaVertice.h"
#include "Monitores.h"

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

// Aplica Disjkstra nele - Talvez precise passar a lista com os todos os vertices
void CalculaDistsMon_Serv(Monitor *mon, Vertice **vetServ, int qtdServ, Vertice **todos, int total);

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