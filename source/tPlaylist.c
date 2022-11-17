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

Playlist *LePLaylist(FILE *pFilePlaylists)
{
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));

    fread(&playlist->qtdMusicas, sizeof(int), 1, pFilePlaylists);
    playlist->indicesDasMusicas = (int *)malloc(sizeof(int)*playlist->qtdMusicas);

    for (int i = 0; i < playlist->qtdMusicas; i++)
    {
        fread(&playlist->indicesDasMusicas[i], sizeof(int), 1, pFilePlaylists);
    }

    fread(&playlist->tamanhoNome, sizeof(int), 1, pFilePlaylists);
    playlist->nome = (char *)malloc(sizeof(char)*playlist->tamanhoNome);

    for (int i = 0; i < playlist->tamanhoNome; i++)
    {
        fread(&playlist->nome[i], sizeof(char), 1, pFilePlaylists);
    }

    return playlist;
}

Playlist *CriaPlaylist(char *nome)
{
    int tamNome = strlen(nome)+1;

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

void EscrevePlaylistBin(Playlist *playlist, FILE *pFilePlaylists)
{
    fwrite(&playlist->qtdMusicas, sizeof(int), 1, pFilePlaylists);

    for (int i = 0; i < playlist->qtdMusicas; i++)
    {
        fwrite(&playlist->indicesDasMusicas[i], sizeof(int), 1, pFilePlaylists);
    }

    fwrite(&playlist->tamanhoNome, sizeof(int), 1, pFilePlaylists);

    for (int i = 0; i < playlist->tamanhoNome; i++)
    {
        fwrite(&playlist->nome[i], sizeof(char), 1, pFilePlaylists);
    }
}

int RetornaQtdMusicasPlaylist(Playlist *p)
{
    return p->qtdMusicas;
}

void ObtemMusicasDaPlaylist(Playlist *p, int *arrayIndices)
{
    static int k=0;

    for (int i = 0; i < p->qtdMusicas; i++, k++)
    {
        arrayIndices[k] = p->indicesDasMusicas[i];
    }
}

void CalculaMediaPlaylist(Playlist *p, Musicas *m, float *mediaPlaylist)
{
    int i;

    AtribuiArrayCaracteristicas(m, mediaPlaylist, p->indicesDasMusicas, p->qtdMusicas);

    for (i = 0; i < 8; i++)
    {
        mediaPlaylist[i] /= p->qtdMusicas;
        if(i)printf(" - ");
        printf("%f", mediaPlaylist[i]);
    }
    printf("\n");
}