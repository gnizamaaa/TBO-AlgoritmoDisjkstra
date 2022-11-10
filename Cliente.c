#include "Vertice.h"
#include "TabelaDist.h"
struct cliente
{
    Vertice *vert;

    // Colocar todos aqui
    Tabeladist *RTTReal;

    // Distancia apenas para os servidores
    // vai ser a distancia do rttreal para o monitor + rtt monitor serv
    Tabeladist *RTTFake;
};