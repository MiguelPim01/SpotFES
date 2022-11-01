#include "tPlaylist.h"

int main(int argc, char *argv[])
{
    FILE *pFileMusicas, *pFileArtistas;
    Musica_pt *ArrayMusicas;
    Artista_pt *ArrayArtistas;
    char caminho[1000];

    // ABERTURA A LEITURA DOS ARQUIVOS

    if (argc <= 1)
    {
        printf("ERRO: Diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }

    // Abrindo arquivos de artistas
    sprintf(caminho, "%s/artists_*.csv", argv[1]);
    pFileArtistas = fopen(caminho, "r");

    if (pFileArtistas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir %s/artists_*.csv", argv[1]);
        return 1;
    }

    // Leitura do arquivo de artistas e alocação dinamica

    ArrayArtistas = CarregaFileArtistas(pFileArtistas, ArrayArtistas);

    // Abrindo arquivo de musicas
    sprintf(caminho, "%s/tracks_*.csv", argv[1]);
    pFileMusicas = fopen(caminho, "r");

    if (pFileMusicas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir %s/tracks_*.csv", argv[1]);
        return 1;
    }

    // Leitura do arquivo de musicas e alocação dinamica

    ArrayMusicas = CarregaFileMusicas(pFileMusicas, ArrayMusicas);

    // -- Fechar arquivos --

    fclose(pFileArtistas);
    fclose(pFileMusicas);

    // -- Liberar espaço de memoria do heap --

    LiberaArrayMusicas(ArrayMusicas);
    LiberaArrayArtistas(ArrayArtistas);
}