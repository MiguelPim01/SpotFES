#ifndef _TARTISTAS_H_
#define _TARTISTAS_H_
#include "tArtista.h"

#include "tArtista.h"

typedef struct tArtistas Artistas;

/*
 * Recebe um arquivo de artistas e retorna um ponteiro para onde eles serao armazenados
 */
Artistas * CarregaArquivoArtistas(FILE *pFileArtistas, Artistas *a);

/*
 * Libera vetor de artistas da memoria
 */
void LiberaArtistas(Artistas *a);

void ImprimeDadosDosArtistas(Artistas *a);

Artista **ObtemArtistas(Artista **arrayArtistas, char *id_artistas, Artistas *a, int qtdArtistasMusica);

void ImprimeVetorDeArtistas(Artista **arrayArtistas, int qtdArtistas);

#endif