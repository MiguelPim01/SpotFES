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

Musica *LeMusica(char *buffer, int contMusicas)
{
    Musica *musica = (Musica *)malloc(sizeof(Musica));
    

    char id[70], nome[200], artistas[900], id_artistas[1060], data[50];
    id[0]='\0'; nome[0]='\0'; artistas[0]='\0'; id_artistas[0]='\0'; data[0]='\0'; // Inicializando
    
    // Fazendo leitura da musica
    if (sscanf(buffer, "%[^;];%[^;];%d;%d;%d;%[^;];%[^;];%[^;];%f;%f;%d;%f;%d;%f;%f;%f;%f;%f;%f;%d\n", 
        id, nome, &musica->popularity, &musica->duracao_ms, &musica->explicit, artistas, id_artistas, data, 
        &musica->danceability, &musica->energy, &musica->key, &musica->loudness, &musica->mode, &musica->speechiness,
        &musica->acousticness, &musica->instrumentalness, &musica->liveness, &musica->valence, &musica->tempo, &musica->time_signature) != 20)
        {
            printf("ERRO NA LEITURA DA MUSICA! LINHA: %d\n", contMusicas);
        }


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
    /*int i, qtd = RetornaQtdArtistasDaMusica(musica);
    for(i=0; i<qtd; i++) {
        ImprimeArtista(musica->arrayArtistas[i]);
    }*/
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
    printf("Instrumentalness: %.10f\n", musica->instrumentalness);
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

void ImprimeMusicaRelatorio(Musica *m, FILE *pFileRelatorio) 
{
    fprintf(pFileRelatorio, "id: %s, nome: %s, artistas: %s\n", m->id, m->nome, m->artistas);
}

void AdicionaValoresCaracteristicas(Musica *m, float *mediaPlaylist)
{
    mediaPlaylist[0] += m->danceability;
    mediaPlaylist[1] += m->energy;
    mediaPlaylist[2] += m->mode;
    mediaPlaylist[3] += m->speechiness;
    mediaPlaylist[4] += m->acousticness;
    mediaPlaylist[5] += m->instrumentalness;
    mediaPlaylist[6] += m->liveness;
    mediaPlaylist[7] += m->valence;
}

float CalculaDistancia(Musica *m, float *mediaPlaylist)
{
    float somatorio = 0.0, distancia = 0.0;

    somatorio += pow(m->danceability - mediaPlaylist[0], 2);
    somatorio += pow(m->energy - mediaPlaylist[1], 2);
    somatorio += pow(m->mode - mediaPlaylist[2], 2);
    somatorio += pow(m->speechiness - mediaPlaylist[3], 2);
    somatorio += pow(m->acousticness - mediaPlaylist[4], 2);
    somatorio += pow(m->instrumentalness - mediaPlaylist[5], 2);
    somatorio += pow(m->liveness - mediaPlaylist[6], 2);
    somatorio += pow(m->valence - mediaPlaylist[7], 2);

    distancia = sqrt(somatorio);

    return distancia;
}

char *ObtemIdMusica(Musica *musica)
{
    return musica->id;
}

int RetornaQtdArtistasMusica(Musica *musica)
{
    return musica->qtdArtistas;
}

void PoeIndicesArtistasArray(Musica *m, Artistas *a, int *arrayIndicesArtistas)
{
    int i;

    for (i = 0; i < m->qtdArtistas; i++)
    {
        PoeIndiceDeUmArtistaNaArray(a, m->arrayArtistas[i], arrayIndicesArtistas);
    }

}