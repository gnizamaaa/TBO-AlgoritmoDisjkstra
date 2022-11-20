#include "Cliente.h"
#include "Vertice.h"
#include "Servidor.h"
#include "Monitores.h"

int main(int argc, char *argv[])
{
    char *entrada = "entrada.txt";
    char *saida = "teste.txt";

    FILE *arqEnt = fopen(entrada, "r");
    int tamV, tamE, tamS, tamC, tamM;

    fscanf(arqEnt, "%i %i", &tamV, &tamE);
    fscanf(arqEnt, "%i %i %i", &tamS, &tamC, &tamM);

    Vertice **total = malloc(sizeof(Vertice *) * tamV);
    for (int i = 0; i < tamV; i++)
    {
        total[i] = IniciaVertice(i, tamV);
    }

    Vertice **servidores = malloc(sizeof(Vertice *) * tamS);
    Cliente **clientes = malloc(sizeof(Cliente *) * tamC);
    Monitor **monitores = malloc(sizeof(Monitor *) * tamM);

    for (int i = 0; i < tamS; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        servidores[i] = total[temp];
    }

    for (int i = 0; i < tamC; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        clientes[i] = IniciaCliente(total[temp], tamS);
    }

    for (int i = 0; i < tamM; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        monitores[i] = IniciaMonitor(total[temp], tamS);
    }

    for (int i = 0; i < tamE; i++)
    {
        int orig, dest;
        double dist;
        fscanf(arqEnt, "%i %i %f", &orig, &dest, &dist);
        ConectaVertice(total[orig], total[dest], dist);
    }

    // for (int i = 0; i < tamM; i++)
    // {
    //     CalculaDistsMon_Serv(monitores[i], servidores, tamS, total, tamV);
    // }

    for (int i = 0; i < tamV; i++)
    {
        printf("%i\n", GetID(total[i]));
        for (int j = 0; j < tamV; j++)
        {
            if (IsConnected(total[i], total[j]))
            {
                printf("%i %i\n", GetID(total[i]), GetID(total[j]));
            }
        }
    }

    // Liberando a memoria alocada
    for (int i = 0; i < tamC; i++)
    {
        LiberaCliente(clientes[i]);
    }
    free(clientes);

    for (int i = 0; i < tamM; i++)
    {
        LiberaMonitor(monitores[i]);
    }
    free(monitores);

    for (int i = 0; i < tamV; i++)
    {
        LiberaVertice(total[i]);
    }
    free(total);
    free(servidores);

    fclose(arqEnt);
}