#include <stdio.h>

#include "tArtistas.h"
#include "tMusicas.h"
#include "tPlaylists.h"

int main(int argc, char *argv[])
{
    FILE *pFileMusicas, *pFileArtistas, *pFilePlaylists;
    Artistas *artistas;
    Musicas *musicas;
    char caminho[500];

    artistas = NULL;
    musicas = NULL;

    // ABERTURA E LEITURA DOS ARQUIVOS

    if (argc <= 1)
    {
        printf("ERRO: Diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }

    // Abrindo arquivos de artistas
    sprintf(caminho, "%s.csv", argv[1]);
    pFileArtistas = fopen(caminho, "r");

    if (pFileArtistas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s.csv\n", argv[1]);
        return 1;
    }

    // Leitura do arquivo de artistas e alocação dinamica
    artistas = CarregaArquivoArtistas(pFileArtistas, artistas);

    // Abrindo arquivo de musicas
    sprintf(caminho, "%s.csv", argv[2]);
    pFileMusicas = fopen(caminho, "r");

    if (pFileMusicas == NULL)
    {
        printf("ERRO: Nao foi possivel abrir %s.csv\n", argv[2]);
        return 1;
    }

    // Leitura do arquivo de musicas e alocação dinamica
    musicas = CarregaArquivoMusicas(pFileMusicas, musicas);

    // Fechar arquivos
    fclose(pFileArtistas);
    fclose(pFileMusicas);

    // Relacionar artistas com as musicas que fazem parte
    RelacionaArrayDeMusicasEArtistas(musicas, artistas);


    // FUNCIONAMENTO DO PROGRAMA:

    int flagBreak=0, indiceMusica=0, indicePlaylist=0, aux;
    char opcao, texto[100];
    Playlists *playlists;

    // Abrindo arquivos de playlists
    sscanf(argv[1], "data/artists_%d", &aux);
    sprintf(caminho, "playlists_%d.bin", aux);
    pFilePlaylists = fopen(caminho, "rb");

    if (pFilePlaylists == NULL)
    {
        playlists = InicializaPlaylists();
    }
    else 
    {
        playlists = CarregaArquivoPlaylists(pFilePlaylists);
        fclose(pFilePlaylists);
    }

    printf("==================================\n");
    printf("Selecione uma opção:\n");
    printf("\n1 - Buscar Musica\n2 - Listar Musica\n3 - Criar Playlist\n4 - Listar Playlists\n5 - Listar uma playlist\n6 - Adicionar musica a playlist\n7 - Recomendar Musica\n8 - Gerar Relatorio e Sair\n");
    printf("==================================\n");
    printf("--> ");

    while (scanf("%c", &opcao) == 1)
    {
        scanf("%*[^\n]");
        scanf("%*c");
        switch (opcao)
        {
            // 1 - Buscar musica:
            case '1':
                printf("\nBusque uma musica:\n--> ");
                scanf("%[^\n]", texto);
                scanf("%*c");
                BuscaMusicas(musicas, texto);
                
                break;

            // 2 - Listar uma musica:
            case '2':
                printf("\nDigite o indice da musica:\n--> ");
                scanf("%d", &indiceMusica);
                scanf("%*[^\n]");
                scanf("%*c");
                BuscaIndiceDaMusica(musicas, indiceMusica);
                
                // 2.1 - Executar uma musica:
                break;
            
            // 3 - Criar uma playlist:
            case '3':
                printf("\nDigite o nome de sua playlist:\n--> ");
                scanf("%[^\n]", texto);
                scanf("%*c");

                AdicionaPlaylist(playlists, texto);
                
                break;

            // 4 - Listar playlists:
            case '4': 
                ListarPlaylists(playlists);
                
                break;

            // 5 - Listar uma playlist:
            case '5':
                printf("\nDigite o indice da playlist:\n--> ");
                scanf("%d", &indiceMusica);
                scanf("%*[^\n]");
                scanf("%*c");

                ListaUmaPlaylist(playlists, musicas, indiceMusica);
                
                break;

            // 6 - Adicionar uma musica na playlist:
            case '6':
                printf("Digite o indice da playlist:\n--> ");
                scanf("%d", &indicePlaylist);
                scanf("%*[^\n]");
                scanf("%*c");
                
                printf("\nDigite o indice da musica\n--> ");
                scanf("%d", &indiceMusica);
                scanf("%*[^\n]");
                scanf("%*c");

                AdicionaMusicaPlaylist(playlists, indiceMusica, indicePlaylist);
                
                break;

            // 7 - Recomendar musicas parecidas com uma playlist:
            case '7':
                
                break;

            // 8 - Gerar relatorio:
            case '8':
                flagBreak = 1;
                break;
            
            default:
                printf("Opção Invalida!\n");
                break;
        } // FIM DO SWITCH

        if (flagBreak)
        {
            break;
        }

        printf("==================================\n");
        printf("Selecione uma opção:\n");
        printf("\n1 - Buscar Musica\n2 - Listar Musica\n3 - Criar Playlist\n4 - Listar Playlists\n5 - Listar uma playlist\n6 - Adicionar musica a playlist\n7 - Recomendar Musica\n8 - Gerar Relatorio e Sair\n");
        printf("==================================\n");
        printf("--> ");

    } // FIM DO WHILE

    pFilePlaylists = fopen(caminho, "wb");

    if (pFilePlaylists == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s para escrita\n", caminho);
    }
    else 
    {
        SalvaPlaylists(playlists, pFilePlaylists);
        fclose(pFilePlaylists);
    }

    // Liberar espaço da memoria
    LiberaMusicas(musicas);
    LiberaArtistas(artistas);
    LiberaPlaylists(playlists);

    return 0;
}