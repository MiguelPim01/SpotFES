#ifndef _TPLAYLISTS_H_
#define _TPLAYLISTS_H_

#include "tMusicas.h"
#include "tArtistas.h"

typedef struct tPlaylists Playlists;

Playlists *CarregaArquivoPlaylists(FILE *pFilePlaylists);

Playlists *InicializaPlaylists();

void AdicionaPlaylist(Playlists *p, char *nome);

void LiberaPlaylists(Playlists *p);

void ListarPlaylists(Playlists *p);

void ListaUmaPlaylist(Playlists *p, Musicas *m, int indice);

void AdicionaMusicaPlaylist(Playlists *p, int indiceMusica, int indicePlaylist);

int ObtemTamanhoArrayIndices(Playlists *p);

void RecomendaMusicas(Playlists *p, Musicas *m, int indicePlaylist, int k);

void SalvaPlaylists(Playlists *p, FILE *pFilePlaylists);

void GerarRelatorio(Playlists *p, Musicas *m, Artistas *a, FILE *pFileRelatorioM, FILE *pFileRelatorioA);

#endif