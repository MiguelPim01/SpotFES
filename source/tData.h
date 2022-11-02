#ifndef _TDATA_H_
#define _TDATA_H_

typedef struct tData Data;

/*
 * Inicializa e faz a alocação da data a partir de parametros dados
 */
Data *InicializaData(int dia, int mes, int ano);

#endif