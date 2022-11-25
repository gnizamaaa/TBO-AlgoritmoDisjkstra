#include "Vertice.h"
#include "TabelaDist.h"
#include "Cliente.h"
#include "PQ.h"
#include "Monitores.h"

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

void Atualizafila1(Vertice *vert, double custo, PQ *fila, double custoVertAtual)
{
    if (PQ_get_key(fila, GetID(vert)) > custo + custoVertAtual)
    {
        PQ_decrease_key(fila, GetID(vert), custo + custoVertAtual);
    }
}

void CalculaDistsCli_Serv(Cliente *cli, Servidor **vetServ, int qtdServ, Monitor **vetMon, int qtdMon, Vertice **todos, int total)
{
    Tabeladist *RTTMon = IniciaTabela(total);

    PQ *fila = PQ_init(total);
    for (int i = 0; i < total; i++)
    {
        // Inicia tds como infinito
        PQ_insert(fila, todos[i], 9999999999);
    }
    // A origem como 0
    PQ_decrease_key(fila, GetID(cli->vert), 0);

    while (!PQ_empty(fila))
    {
        // Pega a menor chave, remove da fila e atualiza a fila
        double custo = PQ_get_key(fila, GetID(PQ_min(fila)));
        Vertice *removido = PQ_delmin(fila);
        IteraAdj(removido, fila, custo, Atualizafila1);
        // Se eh um servidor, insere na tabela o custo
        if (IsServ(removido))
        {
            Servidor *temp;
            for (int i = 0; i < qtdServ; i++)
            {
                if (GetVerticeServ(vetServ[i]) == removido)
                {
                    temp = vetServ[i];
                    break;
                }
            }
            InsereVert(cli->RTTReal, removido, custo + DistIda(temp, cli->vert));
        }
        else if (IsMon(removido)) // Eh monitor
        {
            Monitor *temp;
            for (int i = 0; i < qtdMon; i++)
            {
                if (GetVerticeMon(vetMon[i]) == removido)
                {
                    temp = vetMon[i];
                    break;
                }
            }
            // Iso daq retornou -1
            InsereVert(RTTMon, removido, custo + Dist_MonCli(temp, cli->vert));
        }
    }
    PQ_finish(fila);

    // printf("\nRTTMON\n");
    // ImprimeTabela(RTTMon);
    // printf("\n");

    // Tabela das feiki
    for (int j = 0; j < qtdServ; j++)
    {
        double menorDist = -1;
        for (int i = 0; i < qtdMon; i++)
        {
            double AtualEst = GetDist(RTTMon, GetVerticeMon(vetMon[i]));
            AtualEst += Dist_MonServ(vetMon[i], GetVerticeServ(vetServ[j]));
            if (menorDist == -1 || menorDist > AtualEst)
            {
                menorDist = AtualEst;
            }
        }
        if (menorDist != -1)
            InsereVert(cli->RTTFake, GetVerticeServ(vetServ[j]), menorDist);
    }

    LiberaTabela(RTTMon);
}

// Retorna a tabela
Tabeladist *getTabela_RTTReal(Cliente *cli)
{
    return cli->RTTReal;
}

Tabeladist *getTabela_RTTFake(Cliente *cli)
{
    return cli->RTTFake;
}

double getRTTReal(Cliente *cli, Vertice *buscado)
{
    return GetDist(cli->RTTReal, buscado);
}
double getRTTFake(Cliente *cli, Vertice *buscado)
{
    return GetDist(cli->RTTFake, buscado);
}

void LiberaCliente(Cliente *alvo)
{
    LiberaTabela(alvo->RTTReal);
    LiberaTabela(alvo->RTTFake);
    free(alvo);
}