#include "Vertice.h"
#include "TabelaDist.h"
#include "Cliente.h"

struct cliente
{
    Vertice *vert;

    // Colocar todos aqui
    Tabeladist *RTTReal;

    // Distancia apenas para os servidores
    // vai ser a distancia do rttreal para o monitor + rtt monitor serv
    Tabeladist *RTTFake;
};

Cliente *IniciaCliente(Vertice *vert, int qtdServ)
{
    Cliente *saida = malloc(sizeof(Cliente));
    saida->vert = vert;
    saida->RTTReal = IniciaTabela(qtdServ);
    saida->RTTFake = IniciaTabela(qtdServ);
    return saida;
}

Vertice *GetVerticeCli(Cliente *mon)
{
    return mon->vert;
}

// Insere o vertice pego com o getVertice do obj a ser inserido
void InsereAresta(Cliente *alvo, Vertice *vertIns, double dist)
{
    ConectaVertice(alvo->vert, vertIns, dist);
}

void CalculaDistsCli_Serv(Cliente *mon, Vertice **vetServ, int qtdServ, Vertice **todos, int total);

// Retorna a tabela
Tabeladist *getTabela_RTTReal(Cliente *mon)
{
    return mon->RTTReal;
}

Tabeladist *getTabela_RTTFake(Cliente *mon)
{
    return mon->RTTFake;
}

void LiberaCliente(Cliente *alvo)
{
    LiberaTabela(alvo->RTTReal);
    LiberaTabela(alvo->RTTFake);
    free(alvo);
}