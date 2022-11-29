#ifndef SAIDA_H
#define SAIDA_H
#include "Cliente.h"
#include "Servidor.h"

/**
 * @brief Organiza os dados para a saida do programa e as imprime para o arquivo de saida
 *
 * @param arqSai
 * @param vetCli
 * @param qntCli
 * @param vetSer
 * @param qntSer
 */
void ImprimeSaida(FILE *arqSai, Cliente **vetCli, int qntCli, Servidor **vetSer, int qntSer);

#endif