#ifndef _TARTISTA_H_
#define _TARTISTA_H_

typedef struct tArtista Artista;

/*
 * Faz a leitura de um artista a partir de um buffer
 */
Artista * LeArtista(char *buffer, int contArtistas);

/*
 * Atribui as strings contidas em Artista para o tipo
 */
void FinalizaArtista(Artista *artista, char *id, char *generos, char *nome);

/*
 * Libera o espaço alocado para um artista da memoria
 */
void LiberaArtista(Artista *a);

void ImprimeArtista(Artista *artista);

char *ObtemIdArtista(Artista *artista);

#endif