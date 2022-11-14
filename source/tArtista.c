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

    if (sscanf(buffer, "%[^;];%d.0;%[^;];%[^;];%d\n", id, &artista->numSeguidores, generos, nome, &artista->popularidade) != 5)
    {
        printf("HOUVE UM ERRO NA LEITURA DO ARTISTA! LINHA: %d\n", contArtista);
    }

    // 07MFWYztDF2wq4U91e4mgg;44.0;-;Louis Armstrong Hot Seven;Carroll Dickerson Orchestra;0
    // 0SZjEe5ez2iiSUatjjaQGT;2653.0;-;Kumar Sanu;Alka Yagnik;Kavita Krishnamurti;12

    FinalizaArtista(artista, id, generos, nome);

    return artista;
}

void FinalizaArtista(Artista *artista, char *id, char *generos, char *nome) 
{
    artista->id = (char *)malloc((strlen(id)+1)*sizeof(char));
    artista->generos = (char *)malloc((strlen(generos)+1)*sizeof(char));
    artista->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));

    strncpy(artista->id, id, strlen(id)+1);
    strncpy(artista->generos, generos, strlen(generos)+1);
    strncpy(artista->nome, nome, strlen(nome)+1);
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