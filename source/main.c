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
    // printf("MUSICAS:\n\n");
    // ImprimeDadosDasMusicas(musicas);
    // printf("\nARTISTAS:\n\n");
    // ImprimeDadosDosArtistas(artistas);

    // Fechar arquivos
    fclose(pFileArtistas);
    fclose(pFileMusicas);

    // Relacionar artistas com as musicas que fazem parte (GUSTAVO)

    int opcao=0, flagBreak=0;
    char texto[100];

    // FUNCIONAMENTO DO PROGRAMA:
    
    printf("Selecione uma opção:\n--> ");

    while (scanf("%d", &opcao) == 1)
    {
        scanf("%*c");
        switch (opcao)
        {
            // 1 - Buscar musica:
            case 1:
                printf("Digite um texto:\n--> ");
                scanf("%[^\n]", texto);
                BuscaMusicas(musicas, texto);
                
                break;

            // 2 - Listar uma musica:
            case 2:
                
                // 2.1 - Executar uma musica:
                break;
            
            // 3 - Criar uma playlist:
            case 3:
                
                break;

            // 4 - Listar playlists:
            case 4:
                
                break;

            // 5 - Listar uma playlist:
            case 5:
                
                break;

            // 6 - Adicionar uma musica na playlist:
            case 6:
                
                break;

            // 7 - Recomendar musicas parecidas com uma playlist:
            case 7:
                
                break;

            // 8 - Gerar relatorio:
            case 8:
                flagBreak = 1;
                break;
            
            default:
                break;
        } // FIM DO SWITCH

        if (flagBreak)
        {
            break;
        }

        printf("Selecione uma opção:\n--> ");

    } // FIM DO WHILE

    // Liberar espaço da memoria
    LiberaMusicas(musicas);
    LiberaArtistas(artistas);

    return 0;
}