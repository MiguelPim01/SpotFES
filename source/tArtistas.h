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

/*
 * Atribui os ponteiros de artistas ao array de artistas contido na musica
 */
Artista **ObtemArtistas(Artista **arrayArtistas, char *id_artistas, Artistas *a, int qtdArtistasMusica);

/*
 * Imprime um array de artistas
 */
void ImprimeVetorDeArtistas(Artista **arrayArtistas, int qtdArtistas);

#endif