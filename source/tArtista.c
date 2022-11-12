#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tArtista.h"

struct tArtista {
    char *id, *generos, *nome;
    int numSeguidores, popularidade;
};

Artista * LeArtista(char *buffer) 
{
    char id[50], generos[300], nome[100];

    // Aloca espaço para um artista
    Artista *artista = (Artista *)malloc(sizeof(Artista));

    sscanf(buffer, "%[^;];%d.0;%[^;];%[^;];%d\n", id, &artista->numSeguidores, generos, nome, &artista->popularidade);

    FinalizaArtista(artista, id, generos, nome);

    return artista;
}

void FinalizaArtista(Artista *artista, char *id, char *generos, char *nome) 
{
    int tamID = strlen(id)+1;
    int tamNome = strlen(nome)+1; 
    int tamGeneros = strlen(generos)+1; 

    artista->id = (char *)malloc(tamID*sizeof(char));
    artista->generos = (char *)malloc(tamGeneros*sizeof(char));
    artista->nome = (char *)malloc(tamNome*sizeof(char));

    strncpy(artista->id, id, tamID);
    strncpy(artista->generos, generos, tamGeneros);
    strncpy(artista->nome, nome, tamNome);
}

int IdIgualAoArtista(Artista *a, char *id) {   
    if (strncmp(id, a->id, strlen(id)) == 0) {
        return 0;
    }
    return 1;
}

void LiberaArtista(Artista *a)
{
    // Liberando ponteiros dentro da struct
    free(a->generos);
    free(a->id);
    free(a->nome);
    
    // Liberando ponteiro que aponta pra struct
    free(a);
}

void ImprimeArtista(Artista *artista)
{
    printf("%s \\ %d \\ %s \\ %s \\ %d", artista->id, artista->numSeguidores, artista->generos, artista->nome, artista->popularidade);
}