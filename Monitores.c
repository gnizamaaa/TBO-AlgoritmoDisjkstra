#include "Vertice.h"
#include "TabelaDist.h"
#include "ListaVertice.h"
#include "Monitores.h"

struct monitor
{
    Vertice *vert;
    // Lista adjacentes
    ListaVertice *adj;
    // Distancia para cada servidor
    Tabeladist *RTTServ;
};

Monitor *IniciaMonitor(int ID, int tamMapa)
{
    Monitor *saida = malloc(sizeof(Monitor));
    saida->adj = inicializaListaVertice(tamMapa);
    saida->vert = IniciaVertice(ID, tamMapa);
    saida->RTTServ = IniciaTabela(tamMapa);
    return saida;
}

Vertice *GetVerticeMon(Monitor *mon)
{
    return mon->vert;
}

// Insere o vertice pego com o getVertice do obj a ser inserido
void InsereAresta(Monitor *alvo, Vertice *vertIns, double dist)
{
    insereListaVertice(alvo->adj, vertIns, dist);
}

// Aplica Disjkstra nele - Talvez precise passar a lista com os todos os vertices
void CalculaDistsMon_Serv(Monitor *mon, Servidor **vetServ, int tam);

// Busca na tabela
double Dist_MonServ(Monitor *mon, Servidor *sev)
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
    liberaLista(alvo->adj);
    LiberaVertice(alvo->vert);
    free(alvo);
}