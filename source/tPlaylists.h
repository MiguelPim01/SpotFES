#ifndef _TPLAYLISTS_H_
#define _TPLAYLISTS_H_

#include "tMusicas.h"

typedef struct tPlaylists Playlists;

Playlists *CarregaArquivoPlaylists(FILE *pFilePlaylists);

Playlists *InicializaPlaylists();

void AdicionaPlaylist(Playlists *p, char *nome);

void LiberaPlaylists(Playlists *p);

void ListarPlaylists(Playlists *p);

void ListaUmaPlaylist(Playlists *p, Musicas *m, int indice);

void AdicionaMusicaPlaylist(Playlists *p, int indiceMusica, int indicePlaylist);

void SalvaPlaylists(Playlists *p, FILE *pFilePlaylists);

#endif