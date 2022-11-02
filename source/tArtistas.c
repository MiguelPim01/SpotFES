#include <stdio.h>
#include <stdlib.h>

#include "tArtistas.h"
#include "tArtista.h"

struct tArtistas {
    Artista **artistas;
};

Artistas * CarregaArquivoArtistas(FILE *pFileArtistas, Artistas *a) {
    int multiplicador=100, contArtistas=0;
    
    //Aloca espaço para struct artistas
    a = (Artistas *)malloc(sizeof(Artistas));

    // Aloca espaço para array de ponteiros de artista (conteúdo da struct artistas)
    a->artistas = (Artista **)malloc(multiplicador*sizeof(Artista *));

    char buffer[1000];
    while (fscanf(pFileArtistas, "%[^\n]\n", buffer) == 1) {
        // Realoca espaço
        if (contArtistas == multiplicador) {
            multiplicador *= 2;
            a->artistas = (Artistas **)realloc(a->artistas, multiplicador*sizeof(Artista *));
        }
        // Cria artista e bota no array de ponteiro de artista
        a->artistas[contArtistas] = CriaArtista(buffer);

        contArtistas++;
    }
}