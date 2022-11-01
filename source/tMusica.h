#ifndef _TMUSICA_H_
#define _TMUSICA_H_

#include <string.h>

#include "tArtista.h"
#include "tData.h"

#define TAM_ID 22

typedef struct tMusica Musica;

typedef Musica * Musica_pt;

/*
 * Faz a leitura do arquivo de musicas e aloca todas elas dinamicamente na memoria
 */
Musica_pt *CarregaFileMusicas(FILE *pFileMusicas, Musica_pt *ArrayMusicas);

/*
 * Faz a leitura de uma musica apenas, que esta no padrao do arquivo
 */
Musica_pt LeMusica(Musica_pt mus, char *buffer);

/*
 * Calcula o tamanho das strings que foram tiradas do arquivo de musicas
 */
static int TamanhoString(char *str);

#endif