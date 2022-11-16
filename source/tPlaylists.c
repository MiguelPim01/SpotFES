#include <stdio.h>
#include <stdlib.h>

#include "tPlaylists.h"
#include "tPlaylist.h"
#include "tMusicas.h"
#include "tArtistas.h"

struct tPlaylists {
    Playlist **playlists;
    int qtdPlaylists;
};

Playlists *CarregaArquivoPlaylists(FILE *pFilePlaylists)
{
    Playlists *p = (Playlists *)malloc(sizeof(Playlists));

    if (fread(&p->qtdPlaylists, sizeof(int), 1, pFilePlaylists) == 1)
    {   
        p->playlists = (Playlist **)malloc(sizeof(Playlist *)*p->qtdPlaylists);
        
        for (int i = 0; i < p->qtdPlaylists; i++)
        {
            p->playlists[i] = LePLaylist(pFilePlaylists);
        }
    }
    else 
    {
        p->qtdPlaylists = 0;
        p->playlists = NULL;
    }

    return p;
}

Playlists *InicializaPlaylists()
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
    if (indice >= 0 && indice < p->qtdPlaylists)
    {
        printf("################\n");
        ImprimePlaylistEMusicas(p->playlists[indice], m);
        printf("################\n");
    }
    else 
    {
        printf("ERRO: Valor do indice invalido!\n");
    }
}

void AdicionaMusicaPlaylist(Playlists *p, int indiceMusica, int indicePlaylist)
{
    if (indicePlaylist >= p->qtdPlaylists)
    {
        printf("ERRO: indice ultrapassou quantidade de playlists!\n");
    }
    else 
    {
        AdicionaMusica(p->playlists[indicePlaylist], indiceMusica);
    }
}

void SalvaPlaylists(Playlists *p, FILE *pFilePlaylists)
{
    fwrite(&p->qtdPlaylists, sizeof(int), 1, pFilePlaylists);

    for (int i = 0; i < p->qtdPlaylists; i++)
    {
        EscrevePlaylistBin(p->playlists[i], pFilePlaylists);
    }
}

void GerarRelatorio(Playlists *p, Musicas *m, Artistas *a, FILE *pFileRelatorio)
{
    int tam = ObtemTamanhoArrayIndices(p);
    int arrayIndices[tam];

    for (int i = 0; i < p->qtdPlaylists; i++)
    {
        ObtemMusicasDaPlaylist(p->playlists[i], arrayIndices);
    }
    ImprimeMusicasOrdenadas(m, arrayIndices, tam, pFileRelatorio);
}

int ObtemTamanhoArrayIndices(Playlists *p)
{
    int i, tam = 0;

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        tam += RetornaQtdMusicasPlaylist(p->playlists[i]);
    }

    return tam;
}

void RecomendaMusicas(Playlists *p, Musicas *m, int indicePlaylist, int k)
{
    int i, j, qtdMusicas = RetornaQtdMusicas(m);
    float mediaPlaylist[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,}, arrayIndicesMusicas[qtdMusicas];

    CalculaMediaPlaylist(p->playlists[indicePlaylist], mediaPlaylist);

    // OrdenaArrayPorDistancia(m, mediaPlaylist, arrayIndicesMusicas);

    ImprimeRecomendacoes(m, arrayIndicesMusicas, k);
}