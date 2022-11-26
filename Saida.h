#ifndef SAIDA_H
#define SAIDA_H
#include "Cliente.h"
#include "Servidor.h"

/**
 * @brief Organiza os dados para a saida do programa e as imprime
 * 
 * @param vetCli 
 * @param qntCli 
 * @param vetSer 
 * @param qntSer 
 */
void ImprimeSaida(Cliente **vetCli, int qntCli, Servidor **vetSer, int qntSer);

#endif