#include <stdio.h>

#include "tArtistas.h"
#include "tMusicas.h"
#include "tPlaylist.h"

int main(int argc, char *argv[])
{
    FILE *pFileMusicas, *pFileArtistas;
    Artistas *artistas;
    Musicas *musicas;
    char caminho[500];

    // ABERTURA E LEITURA DOS ARQUIVOS

    if (argc <= 1)
    {
        printf("ERRO: Diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }

    // Abrindo arquivos de artistas
    sprintf(caminho, "%s", argv[1]);
    pFileArtistas = fopen(caminho, "r");

    if (pFileArtistas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Leitura do arquivo de artistas e alocação dinamica
    artistas = CarregaArquivoArtistas(pFileArtistas, artistas);

    // Abrindo arquivo de musicas
    sprintf(caminho, "%s", argv[2]);
    pFileMusicas = fopen(caminho, "r");

    if (pFileMusicas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir %s\n", argv[2]);
        return 1;
    }

    // Leitura do arquivo de musicas e alocação dinamica
    musicas = CarregaArquivoMusicas(pFileMusicas, musicas);

    // Imprimindo para verificação (temporario)
    ImprimeDadosDasMusicas(musicas);
    ImprimeDadosDosArtistas(artistas);

    // Fechar arquivos
    fclose(pFileArtistas);
    fclose(pFileMusicas);

    // Relacionar artistas com as musicas que fazem parte (PENDENTE)

    // Liberar espaço da memoria
    LiberaMusicas(musicas);
    LiberaArtistas(artistas);

    return 0;
}