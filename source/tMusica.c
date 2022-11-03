#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tMusica.h"
#include "tArtistas.h"
#include "tData.h"

#define TAM_ID 22

struct tMusica {
    Artistas *arrayArtistas;
    Data *data;
    int qtdArtistas, duracao_ms, popularity, explicit, mode, time_signature, key;
    float tempo, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence;
    char *id, *nome, *artistas, *id_artistas;
};

Musica *LeMusica(char *buffer)
{
    Musica *musica = (Musica *)malloc(sizeof(Musica));
    
    int dia, mes, ano;
    float aux1;
    int aux2;
    char id[TAM_ID], nome[50], artistas[100], id_artistas[200];
    
    // Fazendo leitura da musica
    sscanf(buffer, "%[^;];%[^;];%d;%d;%d;%[^;];%[^;];%d-%d-%d;%f;%f;%d;%f;%d;%f;%f;%fe%d;%f;%f;%f;%d\n", 
        id, nome, &musica->popularity, &musica->duracao_ms, &musica->explicit, artistas, id_artistas, &ano, &mes, &dia, 
        &musica->danceability, &musica->energy, &musica->key, &musica->loudness, &musica->mode, &musica->speechiness,
        &musica->acousticness, &aux1, &aux2, &musica->liveness, &musica->valence, &musica->tempo, &musica->time_signature);
    
    
    musica->data = InicializaData(dia, mes, ano);

    musica->instrumentalness = aux1*pow(10, aux2);

    // Atribuindo id, nome, artistas e id_artistas a musica
    FinalizaMusica(musica, id, nome, artistas, id_artistas);

    return musica;
}

void FinalizaMusica(Musica *musica, char *id, char *nome, char *artistas, char *id_artistas)
{
    // Alocando espaço para cada uma das strings
    musica->id = (char *)malloc(strlen(id)*sizeof(char)+1);
    musica->nome = (char *)malloc(strlen(nome)*sizeof(char)+1);
    musica->artistas = (char *)malloc(strlen(artistas)*sizeof(char)+1);
    musica->id_artistas = (char *)malloc(strlen(id_artistas)*sizeof(char)+1);

    // Passando as strings para a musica
    strcpy(musica->id, id);
    strcpy(musica->nome, nome);
    strcpy(musica->artistas, artistas);
    strcpy(musica->id_artistas, id_artistas);
}

void LiberaMusica(Musica *m)
{
    // Liberando ponteiros que estao na struct
    //LiberaArtistas(m->arrayArtistas);
    LiberaData(m->data);
    free(m->id);
    free(m->nome);
    free(m->artistas);
    free(m->id_artistas);

    // Liberando o ponteiro que aponta para a struct
    free(m);
}

void ImprimeMusica(Musica *musica)
{
    printf("%s", musica->nome);
}