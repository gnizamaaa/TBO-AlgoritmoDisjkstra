#include "TabelaDist.h"
#include "Vertice.h"

typedef struct set Set;

struct set
{
    Vertice *vert;
    double dist;
};

// Tabela vertice-custo
//  Implementar com alguma forma de otimizacao para n precisar busca O(n)
//  Pode usar o id como chave de busca mas tem q colocar %tam
//  colocar lista dessa celula(vert-custo) em cada pos consequentmente
//  Ai qnd for buscar, vem e busca dentro dessa lista
typedef struct table Tabeladist;

struct table
{
    Set **vet;
    int tam;
    int MAX;
};

int hashCode(Vertice *vert)
{
    return GetID(vert);
}

Tabeladist *IniciaTabela(int tam)
{
    Tabeladist *saida = malloc(sizeof(Tabeladist));
    saida->MAX = tam;
    saida->tam = 0;
    saida->vet = malloc((tam) * sizeof(Set *));

    for (int i = 0; i < tam; i++)
    {
        saida->vet[i] = NULL;
    }

    return saida;
}

void InsereVert(Tabeladist *alvo, Vertice *vertIns, double dist)
{
    if (alvo->tam >= alvo->MAX)
        return;

    // get the hash
    int hashIndex = hashCode(vertIns) % alvo->MAX;

    // move in array until an empty
    while (alvo->vet[hashIndex] != NULL)
    {
        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= alvo->MAX;
    }

    Set *inserido = malloc(sizeof(Set));
    inserido->vert = vertIns;
    inserido->dist = dist;

    alvo->vet[hashIndex] = inserido;
    alvo->tam++;
    return;
}

double GetDist(Tabeladist *alvo, Vertice *vertBus)
{
    // get the hash
    int hashIndex = hashCode(vertBus);

    int i = 0;
    // move in array until an empty
    while (alvo->vet[hashIndex] != NULL && i < alvo->tam)
    {

        // Checa se eh o buscado
        if (alvo->vet[hashIndex]->vert == vertBus)
            return alvo->vet[hashIndex]->dist;

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= alvo->MAX;
        i++;
    }

    return -1;
}

void AtualizaDist(Tabeladist *alvo, Vertice *vertBus, double dist)
{
    // get the hash
    int hashIndex = hashCode(vertBus);

    int i = 0;
    // move in array until an empty
    while (alvo->vet[hashIndex] != NULL && i < alvo->tam)
    {

        // Checa se eh o buscado
        if (alvo->vet[hashIndex]->vert == vertBus)
        {
            alvo->vet[hashIndex]->dist = dist;
            return;
        }

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= alvo->MAX;
        i++;
    }
}

void ImprimeTabela(Tabeladist *alvo)
{
    for (int i = 0; i < alvo->tam; i++)
    {
        if (alvo->vet[i] != NULL)
        {
            double temp = alvo->vet[i]->dist;
            printf("%i - %lf\n", GetID(alvo->vet[i]->vert), temp);
        }
    }
}

void LiberaTabela(Tabeladist *alvo)
{
    for (int i = 0; i < alvo->MAX; i++)
        free(alvo->vet[i]);
    free(alvo->vet);
    free(alvo);
}
