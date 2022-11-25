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

    for (int i = 0; i < tamS; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        // servidores[i] = total[temp];
        servidores[i] = IniciaServidor(total[temp], tamV+7);
        SetTipo(total[temp], 'S');
    }

    for (int i = 0; i < tamC; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        clientes[i] = IniciaCliente(total[temp], tamV+7);
        SetTipo(total[temp], 'C');
    }

    for (int i = 0; i < tamM; i++)
    {
        int temp;
        fscanf(arqEnt, "%i", &temp);
        monitores[i] = IniciaMonitor(total[temp], tamV, tamV+7);
        SetTipo(total[temp], 'M');
    }

    for (int i = 0; i < tamE; i++)
    {
        int orig, dest;
        double dist = 0;
        fscanf(arqEnt, "%i %i %lf", &orig, &dest, &dist);
        ConectaVertice(total[orig], total[dest], dist);
    }

    // Processamento
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

    // printf("%i - %i\n", GetID(GetVerticeMon(monitores[0])), GetID(GetVerticeServ(servidores[0])));
    // ImprimeTabela(getTabela_MonServ(monitores[0]));
    // ImprimeTabela(getTabela_MonCli(monitores[0]));

    // printf("\n%i - %i\n", GetID(GetVerticeMon(monitores[1])), GetID(GetVerticeServ(servidores[0])));
    // ImprimeTabela(getTabela_MonServ(monitores[1]));
    // ImprimeTabela(getTabela_MonCli(monitores[1]));

    // printf("\n%i - %i\n", GetID(GetVerticeCli(clientes[0])), GetID(GetVerticeServ(servidores[0])));
    // ImprimeTabela(getTabela_RTTReal(clientes[0]));
    // printf("oi\n");
    // ImprimeTabela(getTabela_RTTFake(clientes[0]));

    ImprimeSaida(clientes, tamC, servidores, tamS);

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