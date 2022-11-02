#ifndef _TARTISTA_H_
#define _TARTISTA_H_

typedef struct tArtista Artista;

Artista * CriaArtista(char *buffer);

void FinalizaArtista(Artista *artista, char *id, char *generos, char *nome);

#endif