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

void RecomendaMusicas(Playlists *p, Musicas *m, int indicePlaylist, int k)
{
    int qtdMusicas = RetornaQtdMusicas(m), arrayIndicesMusicas[qtdMusicas], i;
    float mediaPlaylist[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // Inicializa array indices de musicas
    for (i = 0; i < qtdMusicas; i++)
    {
        arrayIndicesMusicas[i] = i;
    }

    CalculaMediaPlaylist(p->playlists[indicePlaylist], m, mediaPlaylist);

    OrdenaArrayPorDistancia(m, mediaPlaylist, arrayIndicesMusicas);

    ImprimeRecomendacoes(m, arrayIndicesMusicas, k);
}

void GerarRelatorio(Playlists *p, Musicas *m, Artistas *a, FILE *pFileRelatorioM, FILE *pFileRelatorioA)
{
    // Relatório das músicas
    int i, qtdMusicas = 0;

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        // Obter a quantidade de músicas na playlist para ser o tamanho do vetor
        qtdMusicas += RetornaQtdMusicasPlaylist(p->playlists[i]);
    }

    int arrayIndicesMusicas[qtdMusicas];

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        // Preenche vetor com índices das músicas que estão na playlist
        ObtemMusicasDaPlaylist(p->playlists[i], arrayIndicesMusicas);
    }
    ImprimeMusicasOrdenadas(m, arrayIndicesMusicas, qtdMusicas, pFileRelatorioM);

    // Relatório dos artistas
    int qtdMaxArtistas = 0;

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        // Obter a quantidade máxima possível de artistas para ser o tamanho máximo do vetor
        qtdMaxArtistas += RetornaQtdMaxArtistasPlaylist(p->playlists[i], m);
    }

    int arrayIndicesArtistas[qtdMaxArtistas];
    printf("qtd: %d\n", qtdMaxArtistas);

    for (i = 0; i < p->qtdPlaylists; i++)
    {
        // Preenche vetor com índices dos artistas que estão na playlist
        ObtemIndiceArtistasPlaylist(p->playlists[i], m, a, arrayIndicesArtistas);
    }
    for (i = 0; i < qtdMaxArtistas; i++)
    {
        if (i) printf(" \\ ");
        printf("%d", arrayIndicesArtistas[i]);
    }
    // Ordena array de forma decrescente e o imprime
    ImprimeArtistasOrdenados(a, arrayIndicesArtistas, qtdMaxArtistas, pFileRelatorioA);
    for (i = 0; i < qtdMaxArtistas; i++)
    {
        if (i) printf(" \\ "); else printf("\n");
        printf("%d", arrayIndicesArtistas[i]);
    }
}