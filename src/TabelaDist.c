#include "TabelaDist.h"
#include "Vertice.h"

typedef struct set Set;

struct set
{
    Vertice *vert;
    double dist;
};

/**
 * @brief Tabela vertice-custo
//  Implementar com alguma forma de otimizacao para n precisar busca O(n)
//  Pode usar o id como chave de busca mas tem q colocar %tam
//  colocar lista dessa celula(vert-custo) em cada pos consequentmente
//  Ai qnd for buscar, vem e busca dentro dessa lista
 *
 */
typedef struct tabela Tabeladist;

struct tabela
{
    Set **vet;
    int tam;
    int MAX;
};

/**
 * @brief Foi decidida organizar a tabela de modo similar a uma HashTable,
 * utilizando dessa função para obter um valor unico para o vertice a ser inserido
 *
 * @param vert
 * @return int
 */
static int hashCode(Vertice *vert)
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
    // Checa se nao esta cheia
    if (alvo->tam >= alvo->MAX)
        return;

    int indice = hashCode(vertIns) % alvo->MAX;

    // Move no array ate achar uma pos vazia
    while (alvo->vet[indice] != NULL)
    {
        // Avança uma pos
        ++indice;
        indice %= alvo->MAX;
    }

    // Cria um novo set/celula para ser inserido com a informacao
    Set *inserido = malloc(sizeof(Set));
    inserido->vert = vertIns;
    inserido->dist = dist;

    // Insere de fato no vetor
    alvo->vet[indice] = inserido;
    alvo->tam++;
    return;
}

double GetDist(Tabeladist *alvo, Vertice *vertBus)
{
    int Indice = hashCode(vertBus) % alvo->MAX;

    int i = 0;
    // Move no array ate achar uma pos vazia (percorre o vetor)
    while (alvo->vet[Indice] != NULL && i < alvo->tam)
    {

        // Checa se eh o buscado
        if (alvo->vet[Indice]->vert == vertBus)
            return alvo->vet[Indice]->dist;

        // Avança uma pos
        ++Indice;
        Indice %= alvo->MAX;
        i++;
    }

    return -1;
}

void AtualizaDist(Tabeladist *alvo, Vertice *vertBus, double dist)
{
    int indice = hashCode(vertBus);

    int i = 0;
    // Move no array ate achar uma pos vazia (percorre o vetor)
    while (alvo->vet[indice] != NULL && i < alvo->tam)
    {

        // Checa se eh o buscado
        if (alvo->vet[indice]->vert == vertBus)
        {
            alvo->vet[indice]->dist = dist;
            return;
        }

        // Avança uma pos
        ++indice;
        indice %= alvo->MAX;
        i++;
    }
}

void ImprimeTabela(Tabeladist *alvo)
{
    for (int i = 0; i < alvo->MAX; i++)
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
