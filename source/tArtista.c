#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tArtista.h"

struct tArtista {
    char *id, *generos, *nome;
    int numSeguidores, popularidade;
};

Artista * LeArtista(char *buffer, int contArtista) 
{
    char id[50], generos[300], nome[100];

    // Aloca espaço para um artista
    Artista *artista = (Artista *)malloc(sizeof(Artista));

    // Leitura e verificação da leitura de artistas
    if (sscanf(buffer, "%[^;];%d.0;%[^;];%[^;];%d\n", id, &artista->numSeguidores, generos, nome, &artista->popularidade) != 5)
    {
        printf("HOUVE UM ERRO NA LEITURA DO ARTISTA! LINHA: %d\n", contArtista);
    }

    // Atribuindo id, generos e nome ao artista
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
    printf("id: %s, nome: %s, Seguidores: %d, generos: %s, popularidade: %d\n", artista->id,  artista->nome, artista->numSeguidores, artista->generos, artista->popularidade);
}

char *ObtemIdArtista(Artista *artista)
{
    return artista->id;
}