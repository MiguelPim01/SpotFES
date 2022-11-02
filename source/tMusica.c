#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char id[TAM_ID], nome[50], artistas[100], id_artistas[200];
    
    // Fazendo leitura da musica
    sscanf(buffer, "%[^;]", id);
    sscanf(buffer, ";%[^;]", nome);
    sscanf(buffer, ";%d", &musica->popularity);
    sscanf(buffer, ";%d", &musica->duracao_ms);
    sscanf(buffer, ";%d", &musica->explicit);
    sscanf(buffer, ";%[^;]", artistas);
    sscanf(buffer, ";%[^;]", id_artistas);
    
    sscanf(buffer, ";%d-%d-%d", &ano, &mes, &dia);
    musica->data = InicializaData(dia, mes, ano);

    sscanf(buffer, ";%f", &musica->danceability);
    sscanf(buffer, ";%f", &musica->energy);
    sscanf(buffer, ";%d", &musica->key);
    sscanf(buffer, ";%f", &musica->loudness);
    sscanf(buffer, ";%d", &musica->mode);
    sscanf(buffer, ";%f", &musica->speechiness);
    sscanf(buffer, ";%f", &musica->acousticness);
    sscanf(buffer, ";%f", &musica->instrumentalness);
    sscanf(buffer, ";%f\n", &musica->liveness);

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
    LiberaArtistas(m->arrayArtistas);
    LiberaData(m->data);
    free(m->id);
    free(m->nome);
    free(m->artistas);
    free(m->id_artistas);

    // Liberando o ponteiro que aponta para a struct
    free(m);
}