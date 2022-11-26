#include "Cliente.h"
#include "Vertice.h"
#include "Servidor.h"
#include "Monitores.h"
#include "Saida.h"

int main(int argc, char *argv[])
{
    char *entrada = "entrada.txt";
    char *saida = "teste.txt";

    FILE *arqEnt = fopen(entrada, "r");
    int tamV, tamE, tamS, tamC, tamM;


    //***************** Leitura do arquivo de entrada

    fscanf(arqEnt, "%i %i", &tamV, &tamE);
    fscanf(arqEnt, "%i %i %i", &tamS, &tamC, &tamM);

    Vertice **total = malloc(sizeof(Vertice *) * tamV);
    for (int i = 0; i < tamV; i++)
    {
        total[i] = IniciaVertice(i, tamV);
    }

    Servidor **servidores = malloc(sizeof(Vertice *) * tamS);
    Cliente **clientes = malloc(sizeof(Cliente *) * tamC);
    Monitor **monitores = malloc(sizeof(Monitor *) * tamM);

    //Leitura de servidores
    for (int i = 0; i < tamS; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        servidores[i] = IniciaServidor(total[temp], tamV);
        SetTipo(total[temp], 'S');
    }

    //Leitura de clientes
    for (int i = 0; i < tamC; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        clientes[i] = IniciaCliente(total[temp], tamS);
        SetTipo(total[temp], 'C');
    }

    //Leitura de monitores
    for (int i = 0; i < tamM; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        monitores[i] = IniciaMonitor(total[temp], tamS, tamC);
        SetTipo(total[temp], 'M');
    }

    //Leitura de arestas
    for (int i = 0; i < tamE; i++)
    {
        int orig, dest;
        double dist = 0;
        fscanf(arqEnt, "%i %i %lf", &orig, &dest, &dist);
        ConectaVertice(total[orig], total[dest], dist);
    }

    //***************** Processamento
    for (int i = 0; i < tamS; i++)
    {
        CalculaSaidaServ(servidores[i], total, tamV);
    }

    for (int i = 0; i < tamM; i++)
    {
        CalculaDistsMon_Serv(monitores[i], servidores, tamS, total, tamV);
    }

    for (int i = 0; i < tamC; i++)
    {
        CalculaDistsCli_Serv(clientes[i], servidores, tamS, monitores, tamM, total, tamV);
    }

    //***************** Saida
    ImprimeSaida(clientes, tamC, servidores, tamS);

    //***************** Liberando a
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

    for (int i = 0; i < tamS; i++)
    {
        LiberaServidor(servidores[i]);
    }
    free(servidores);

    for (int i = 0; i < tamV; i++)
    {
        LiberaVertice(total[i]);
    }
    free(total);

    fclose(arqEnt);
}