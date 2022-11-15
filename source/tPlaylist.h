#ifndef _TPLAYLIST_H_
#define _TPLAYLIST_H_

#include "tMusicas.h"

typedef struct tPlaylist Playlist;

Playlist *CriaPlaylist(char *nome);

void LiberaPlaylist(Playlist *playlist);

void ImprimePlaylist(Playlist *playlist);

void ImprimePlaylistEMusicas(Playlist *playlist, Musicas *m);

void AdicionaMusica(Playlist *playlist, int indiceMusica);

#endif