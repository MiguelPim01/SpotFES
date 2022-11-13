#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tMusica.h"
#include "tArtistas.h"
#include "tArtista.h"

struct tMusica {
    Artista **arrayArtistas;
    int qtdArtistas, duracao_ms, popularity, explicit, mode, time_signature, key;
    float tempo, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence;
    char *id, *nome, *artistas, *id_artistas, *data;
};

Musica *LeMusica(char *buffer)
{
    Musica *musica = (Musica *)malloc(sizeof(Musica));
    
    float aux1=0;
    int aux2=0;
    char id[70], nome[200], artistas[900], id_artistas[1060], data[50], instrumentalness[20];
    
    // Fazendo leitura da musica
    sscanf(buffer, "%[^;];%[^;];%d;%d;%d;%[^;];%[^;];%[^;];%f;%f;%d;%f;%d;%f;%f;%[^;];%f;%f;%f;%d\n", 
        id, nome, &musica->popularity, &musica->duracao_ms, &musica->explicit, artistas, id_artistas, data, 
        &musica->danceability, &musica->energy, &musica->key, &musica->loudness, &musica->mode, &musica->speechiness,
        &musica->acousticness, instrumentalness, &musica->liveness, &musica->valence, &musica->tempo, &musica->time_signature);

    if (strstr(instrumentalness, "e") == NULL)
    {
        sscanf(instrumentalness, "%f", &musica->instrumentalness);
    }
    else 
    {
        sscanf(instrumentalness, "%fe%d", &aux1, &aux2);
        musica->instrumentalness = aux1*pow(10, aux2);
    }
    
    musica->instrumentalness = aux1*pow(10, aux2);

    // Atribuindo id, nome, artistas e id_artistas a musica
    FinalizaMusica(musica, id, nome, artistas, id_artistas, data);

    return musica;
}

void FinalizaMusica(Musica *musica, char *id, char *nome, char *artistas, char *id_artistas, char *data)
{
    int tamID=strlen(id)+1;
    int tamNome=strlen(nome)+1; 
    int tamArtistas=strlen(artistas)+1; 
    int tamIDArtistas=strlen(id_artistas)+1;
    int tamData=strlen(data)+1;
    
    // Alocando espaço para cada uma das strings
    musica->id = (char *)malloc(tamID*sizeof(char));
    musica->nome = (char *)malloc(tamNome*sizeof(char));
    musica->artistas = (char *)malloc(tamArtistas*sizeof(char));
    musica->id_artistas = (char *)malloc(tamIDArtistas*sizeof(char));
    musica->data = (char *)malloc(tamData*sizeof(char));

    // Passando as strings para a musica
    strncpy(musica->id, id, tamID);
    strncpy(musica->nome, nome, tamNome);
    strncpy(musica->artistas, artistas, tamArtistas);
    strncpy(musica->id_artistas, id_artistas, tamIDArtistas);
    strncpy(musica->data, data, tamData);

    musica->qtdArtistas = RetornaQtdArtistasDaMusica(musica);
}

void LiberaMusica(Musica *musica)
{
    // Liberando ponteiros que estao na struct
    free(musica->arrayArtistas);    
    free(musica->id);
    free(musica->nome);
    free(musica->artistas);
    free(musica->id_artistas);
    free(musica->data);

    // Liberando o ponteiro que aponta para a struct
    free(musica);
}

void ImprimeMusica(Musica *musica)
{
    printf("id: %s, nome: %s, artistas: %s\n", musica->id, musica->nome, musica->artistas);
}

int ComparaNomeComTexto(Musica *musica, char *texto)
{
    char *aux = strstr(musica->nome, texto);

    if (aux == NULL)
    {
        return 0;
    }

    return 1;
}

void AtribuiArtistasAMusica(Musica *musica, Artistas *a)
{
    musica->arrayArtistas = (Artista **)malloc(sizeof(Artista *)*musica->qtdArtistas);
    
    musica->arrayArtistas = ObtemArtistas(musica->arrayArtistas, musica->id_artistas, a, musica->qtdArtistas);
}

int RetornaQtdArtistasDaMusica(Musica *m) 
{
    int i=0, cont=0;

    while (m->id_artistas[i] != '\0') 
    {
        if (m->id_artistas[i] == '|') {
            cont++;
        }

        i++;
    }

    return cont+1;
}

void PrintaDadosDaMusicaEArtistas(Musica *musica)
{
    printf("DADOS DA MUSICA:\n");
    ImprimeTudoDaMusica(musica);
    printf("\nDADOS DOS ARTISTAS:\n");
    ImprimeVetorDeArtistas(musica->arrayArtistas, musica->qtdArtistas);
}

void ImprimeTudoDaMusica(Musica *musica)
{
    printf("Id: %s\n", musica->id); // id
    printf("Nome: %s\n", musica->nome); // nome
    printf("Data de lançamento: %s\n", musica->data); // data

    printf("\nAcousticness: %.3f\n", musica->acousticness);
    printf("Danceability: %.3f\n", musica->danceability);
    printf("Duração: %d ms\n", musica->duracao_ms);
    printf("Energy: %.3f\n", musica->energy);
    printf("Explicit: %d\n", musica->explicit);
    printf("Instrumentalness: %.3f\n", musica->instrumentalness);
    printf("Key: %d\n", musica->key);
    printf("Liveness: %.3f\n", musica->liveness);
    printf("Loudness: %.3f\n", musica->loudness);
    printf("Mode: %d\n", musica->mode);
    printf("Popularity: %d\n", musica->popularity);
    printf("Speechness: %.3f\n", musica->speechiness);
    printf("Tempo: %.3f\n", musica->tempo);
    printf("Time Signature: %d\n", musica->time_signature);
    printf("Valence: %.3f\n", musica->valence);
}