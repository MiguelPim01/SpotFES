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
        a->artistas[contArtistas] = LeArtista(buffer);

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

void ImprimeDadosDosArtistas(Artistas *a)
{
    int i;
    for (i = 0; i < a->qtdArtistas; i++)
    {
        ImprimeArtista(a->artistas[i]);
        printf("\n");
    }
}

Artista **ObtemArtistas(Artista **arrayArtistas, char *id_artistas, Artistas *a, int qtdArtistas)
{
    int i=0, cont=0;

    for (i = 0; i < a->qtdArtistas; i++)
    {
        if (strstr(id_artistas, ObtemIdArtista(a->artistas[i])) != NULL)
        {
            arrayArtistas[cont] = a->artistas[i];
            cont++;
        }
        if (cont == qtdArtistas)
        {
            break;
        }
    }

    if (cont < qtdArtistas)
    {
        arrayArtistas[cont] = NULL;
    }

    return arrayArtistas;
}

void ImprimeVetorDeArtistas(Artista **arrayArtistas, int qtdArtistas)
{
    int i;

    for (i = 0; arrayArtistas[i] != NULL || i < qtdArtistas; i++)
    {
        ImprimeArtista(arrayArtistas[i]);
    }
}