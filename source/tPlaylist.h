#ifndef _TPLAYLIST_H_
#define _TPLAYLIST_H_

#include "tMusicas.h"
#include <stdio.h>

typedef struct tPlaylist Playlist;

Playlist *LePLaylist(FILE *pFilePlaylists);

Playlist *CriaPlaylist(char *nome);

void LiberaPlaylist(Playlist *playlist);

void ImprimePlaylist(Playlist *playlist);

void ImprimePlaylistEMusicas(Playlist *playlist, Musicas *m);

void AdicionaMusica(Playlist *playlist, int indiceMusica);

void EscrevePlaylistBin(Playlist *playlist, FILE *pFilePlaylists);

int ObtemMusicasDaPlaylist(Playlist *p, int *arrayIndices);

#endif