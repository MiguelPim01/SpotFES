#include <stdio.h>
#include <stdlib.h>

#include "tPlaylists.h"
#include "tPlaylist.h"
#include "tMusicas.h"

#define QTD_PLAYLISTS 3

struct tPlaylists {
    Playlist **playlists;
    int qtdPlaylists;
};

Playlists *InicializaPlaylist()
{
    Playlists *p = (Playlists *)malloc(sizeof(Playlists));

    p->qtdPlaylists = 0;
    p->playlists = NULL;

    return p;
}

void AdicionaPlaylist(Playlists *p, char *nome)
{   
    p->playlists = (Playlist **)realloc(p->playlists, sizeof(Playlist *)*(p->qtdPlaylists+1));

    p->playlists[p->qtdPlaylists] = CriaPlaylist(nome);

    p->qtdPlaylists++;
}

void LiberaPlaylists(Playlists *p)
{
    int i=0;

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        LiberaPlaylist(p->playlists[i]);
    }

    free(p->playlists);
    free(p);
}

void ListarPlaylists(Playlists *p)
{
    int i=0;

    printf("################\n");
    printf("SUAS PLAYLISTS:\n\n");
    for (i = 0; i < p->qtdPlaylists; i++)
    {
        printf("Indice: %d, ", i);
        ImprimePlaylist(p->playlists[i]);
    }
    printf("################\n");
}

void ListaUmaPlaylist(Playlists *p, Musicas *m, int indice)
{
    printf("################\n");
    ImprimePlaylistEMusicas(p->playlists[indice], m);
    printf("################\n");
}

void AdicionaMusicaPlaylist(Playlists *p, int indiceMusica, int indicePlaylist)
{
    AdicionaMusica(p->playlists[indicePlaylist], indiceMusica);
}