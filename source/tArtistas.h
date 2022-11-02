#ifndef _TARTISTAS_H_
#define _TARTISTAS_H_

typedef struct tArtistas Artistas;

/*
 * Recebe um arquivo de artistas e retorna um ponteiro para onde eles serao armazenados
 */
Artistas * CarregaArquivoArtistas(FILE *pFileArtistas, Artistas *a);

/*
 * Libera vetor de artistas da memoria
 */
void LiberaArtistas(Artistas *a);

#endif