#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tPlaylist.h"
#include "tMusica.h"
#include "tMusicas.h"

struct tPlaylist {
    char *nome;
    int *indicesDasMusicas, qtdMusicas, tamanhoNome;
};

Playlist *CriaPlaylist(char *nome)
{
    int tamNome=strlen(nome)+1;

    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    playlist->nome = (char *)malloc(sizeof(char)*tamNome);

    strncpy(playlist->nome, nome, tamNome);

    playlist->qtdMusicas = 0;
    playlist->tamanhoNome = tamNome;
    playlist->indicesDasMusicas = NULL;

    return playlist;
}

void LiberaPlaylist(Playlist *playlist)
{
    free(playlist->nome);
    free(playlist->indicesDasMusicas);
    free(playlist);
}

void ImprimePlaylist(Playlist *playlist)
{
    printf("nome da playlist: %s, quantidade de musicas: %d\n", playlist->nome, playlist->qtdMusicas);
}

void ImprimePlaylistEMusicas(Playlist *playlist, Musicas *m)
{
    printf("NOME DA PLAYLIST: %s\n", playlist->nome);    
    printf("\nMUSICAS:\n\n");
    
    ImprimeMusicasPorIndices(m, playlist->indicesDasMusicas, playlist->qtdMusicas);
    
}

void AdicionaMusica(Playlist *playlist, int indiceMusica)
{
    playlist->indicesDasMusicas = (int *)realloc(playlist->indicesDasMusicas, sizeof(int)*(playlist->qtdMusicas+1));

    playlist->indicesDasMusicas[playlist->qtdMusicas] = indiceMusica;

    playlist->qtdMusicas++;
}