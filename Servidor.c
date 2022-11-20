#include "Vertice.h"
#include "TabelaDist.h"
#include "Servidor.h"

// TODO: Implementar o servidor!
// ANALISAR NECESSIDADE
struct servidor
{
    Vertice *vert;
};

Servidor *IniciaServidor(Vertice *vert, int qtdServ)
{
    Servidor *saida = malloc(sizeof(Servidor));
    saida->vert = vert;
    return saida;
}

int GetIDServ(Servidor *ser);

Vertice *GetVerticeServ(Servidor *ser);

void InsereArestaServ(Servidor *alvo, Vertice *vertIns, double dist);

void LiberaServidor(Servidor *alvo);
