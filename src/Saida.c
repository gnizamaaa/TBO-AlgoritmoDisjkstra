#include "Saida.h"

typedef struct
{
    int IDCli;
    int IDSer;
    double relacao;
} Cel;

/**
 * @brief Funcao de comparacao de duas celulas com base apenas na distancia
 * 
 * @param e1 
 * @param e2 
 * @return int 
 */
static int CmpCel(const void *e1, const void *e2)
{
    const Cel *c1 = e1, *c2 = e2;
    if (c1->relacao == c2->relacao)
        return 0;
    else if (c1->relacao > c2->relacao)
        return 1;
    else
        return -1;
}

//TODO: Imprimir para arquivo!
void ImprimeSaida(FILE *arqSai, Cliente **vetCli, int qntCli, Servidor **vetSer, int qntSer)
{
    Cel *vetorzao = malloc(sizeof(Cel) * (qntCli * qntSer));
    int count = 0;
    for (int i = 0; i < qntCli; i++)
    {
        for (int j = 0; j < qntSer; j++)
        {
            vetorzao[count].IDCli = GetID(GetVerticeCli(vetCli[i]));
            vetorzao[count].IDSer = GetID(GetVerticeServ(vetSer[j]));
            vetorzao[count].relacao = (getRTTFake(vetCli[i], GetVerticeServ(vetSer[j]))) /
                                      getRTTReal(vetCli[i], GetVerticeServ(vetSer[j]));
            count++;
        }
    }

    qsort(vetorzao, count, sizeof(Cel), CmpCel);

    for (int i = 0; i < count; i++)
    {
        fprintf(arqSai,"%i %i %.16f\n", vetorzao[i].IDSer, vetorzao[i].IDCli, vetorzao[i].relacao);
    }

    free(vetorzao);
}