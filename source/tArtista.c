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

    // GABIGOL É BALLON D'ORR !!!!!!!!!!!!!
    //  FRACOOOOOOOO!!!!!!!!

    return artista;
}

void FinalizaArtista(Artista *artista, char *id, char *generos, char *nome) 
{
    artista->id = (char *)malloc(strlen(id)*sizeof(char)+1);
    artista->generos = (char *)malloc(strlen(generos)*sizeof(char)+1);
    artista->nome = (char *)malloc(strlen(nome)*sizeof(char)+1);

    strcpy(artista->id, id);
    strcpy(artista->generos, generos);
    strcpy(artista->nome, nome);
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