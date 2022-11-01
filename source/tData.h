#ifndef _TDATA_H_
#define _TDATA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tData Data;

typedef Data * Data_pt;

/*
 * Faz a leitura de uma data no padrao "ano-mes-dia"
 */
Data_pt LeData(char *buffer, Data_pt data);

/*
 * Aloca dinamicamente uma data e retorna o ponteiro
 */
Data_pt AlocaData();

#endif