#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tArtistas.h"
#include "tArtista.h"

struct tArtistas {
    Artista **artistas;
    int qtdArtistas;
};

Artistas * CarregaArquivoArtistas(FILE *pFileArtistas, Artistas *a) 
{
    int multiplicador=25, contArtistas=0;
    
    //Aloca espaço para struct artistas
    a = (Artistas *)malloc(sizeof(Artistas));

    // Aloca espaço para array de ponteiros de artista (conteúdo da struct artistas)
    a->artistas = (Artista **)malloc(multiplicador*sizeof(Artista *));

    char buffer[1000];
    while (fscanf(pFileArtistas, "%[^\n]\n", buffer) == 1) 
    {
        // Realoca espaço
        if (contArtistas >= multiplicador) 
        {
            multiplicador *= 2;
            a->artistas = (Artista **)realloc(a->artistas, multiplicador*sizeof(Artista *));
        }

        // Cria artista e bota no array de ponteiro de artista
        a->artistas[contArtistas] = LeArtista(buffer, contArtistas+1);

        contArtistas++;
    }

    a->qtdArtistas = contArtistas;

    return a;
}

void LiberaArtistas(Artistas *a)
{
    // Liberando cada artista separadamente
    int i;
    for (i = 0; i < a->qtdArtistas; i++)
    {
        LiberaArtista(a->artistas[i]);
    }

    // Liberando os ponteiros restantes
    free(a->artistas);
    free(a);
}

Artista **ObtemArtistas(Artista **arrayArtistas, char *id_artistas, Artistas *a, int qtdArtistasMusica)
{
    int i=0, cont=0;
    char *aux;

    if (qtdArtistasMusica == 0)
    {
        return arrayArtistas;
    }

    // Varrer o array de artistas
    for (i = 0; i < a->qtdArtistas; i++)
    {
        // Verifica se existe o id do artista nos id's de artistas da musica
        aux = strstr(id_artistas, ObtemIdArtista(a->artistas[i]));

        if (aux != NULL) // Se existir entra no if
        {
            arrayArtistas[cont] = a->artistas[i];
            cont++;
        }
        if (cont == qtdArtistasMusica) // Se o cont se igualar a quantidade alocada para aquela musica o break é feito
        {
            break;
        }
    }

    // Colocar um ponteiro NULL no fim do array
    if (cont < qtdArtistasMusica)
    {
        arrayArtistas[cont] = NULL;
    }

    return arrayArtistas;
}

void ImprimeVetorDeArtistas(Artista **arrayArtistas, int qtdArtistas)
{
    int i;

    for (i = 0; i < qtdArtistas; i++)
    {
        if (arrayArtistas[i] == NULL)
        {
            break;
        }
        ImprimeArtista(arrayArtistas[i]);
    }
}