#include "Vertice.h"
#include "TabelaDist.h"
#include "ListaVertice.h"

struct monitor
{
    Vertice *vert;
    // Lista adjacentes
    ListaVertice *adj;
    // Distancia para cada servidor
    Tabeladist *RTTServ;
};