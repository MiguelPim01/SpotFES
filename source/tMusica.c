#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tMusica.h"
#include "tArtistas.h"

struct tMusica {
    Artistas *arrayArtistas;
    int qtdArtistas, duracao_ms, popularity, explicit, mode, time_signature, key;
    float tempo, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence;
    char *id, *nome, *artistas, *id_artistas, *data;
};

Musica *LeMusica(char *buffer)
{
    Musica *musica = (Musica *)malloc(sizeof(Musica));
    
    float aux1=0;
    int aux2=0;
    char id[40], nome[50], artistas[100], id_artistas[400], data[20];
    
    // Fazendo leitura da musica
    sscanf(buffer, "%[^;];%[^;];%d;%d;%d;%[^;];%[^;];%[^;];%f;%f;%d;%f;%d;%f;%f;%fe%d;%f;%f;%f;%d\n", 
        id, nome, &musica->popularity, &musica->duracao_ms, &musica->explicit, artistas, id_artistas, data, 
        &musica->danceability, &musica->energy, &musica->key, &musica->loudness, &musica->mode, &musica->speechiness,
        &musica->acousticness, &aux1, &aux2, &musica->liveness, &musica->valence, &musica->tempo, &musica->time_signature);

    musica->instrumentalness = aux1*pow(10, aux2);

    // Atribuindo id, nome, artistas e id_artistas a musica
    FinalizaMusica(musica, id, nome, artistas, id_artistas, data);

    return musica;
}

void FinalizaMusica(Musica *musica, char *id, char *nome, char *artistas, char *id_artistas, char *data)
{
    // Alocando espaço para cada uma das strings
    musica->id = (char *)malloc((strlen(id)+1)*sizeof(char));
    musica->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
    musica->artistas = (char *)malloc((strlen(artistas)+1)*sizeof(char));
    musica->id_artistas = (char *)malloc((strlen(id_artistas)+1)*sizeof(char));
    musica->data = (char *)malloc((strlen(data)+1)*sizeof(char));

    // Passando as strings para a musica
    strncpy(musica->id, id, strlen(id)+1);
    strncpy(musica->nome, nome, strlen(nome)+1);
    strncpy(musica->artistas, artistas, strlen(artistas)+1);
    strncpy(musica->id_artistas, id_artistas, strlen(id_artistas)+1);
    strncpy(musica->data, data, strlen(data)+1);
}

void LiberaMusica(Musica *m)
{
    // Liberando ponteiros que estao na struct
    //LiberaArtistas(m->arrayArtistas);
    free(m->id);
    free(m->nome);
    free(m->artistas);
    free(m->id_artistas);
    free(m->data);

    // Liberando o ponteiro que aponta para a struct
    free(m);
}

void ImprimeMusica(Musica *musica)
{
    printf("%s ", musica->nome);
}