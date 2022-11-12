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
    char id[70], nome[200], artistas[900], id_artistas[1060], data[50];
    
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
    // printf("id: %s, nome: %s, artistas: %s\n", musica->id, musica->nome, musica->artistas);
    int i, qtd = RetornaQtdArtistasDaMusica(musica);
    for(i=0; i<qtd; i++) {
        ImprimeArtista(musica->arrayArtistas[i]);
    }
}

int ComparaNomeComTexto(Musica *musica, char *texto)
{
    int tamTex=strlen(texto), i=0;
    char aux[tamTex+1];

    aux[0] = '\0';

    i = tamTex;
    while (musica->nome[i-1] != '\0')
    {
        strncpy(aux, musica->nome+(i-tamTex), tamTex);

        if (strncmp(texto, aux, tamTex) == 0)
        {
            return 1;
        }
        
        i++;
    }

    return 0;
}

int ComparaIdComTexto(Musica *musica, char *texto)
{
    int tamTex=strlen(texto), i=0;
    char aux[tamTex+1];

    aux[0] = '\0';

    i = tamTex;
    while (musica->id[i-1] != '\0')
    {
        strncpy(aux, musica->id+(i-tamTex), tamTex);

        if (strncmp(texto, aux, tamTex) == 0)
        {
            return 1;
        }
        
        i++;
    }

    return 0;
}

void AtribuiArtistasAMusica(Musica *m, Artistas *as) {
    char id[15][30];
    int i, contPosicaoArray=0, qtdArtistasMus = RetornaQtdArtistasDaMusica(m);
    printf("%d ", qtdArtistasMus);
    
    for (i=1; i<=qtdArtistasMus; i++) {
        /* Caso seja o último artista lido, lê até o ';' que sinaliza o final
        e não até a '|' que separa os artistas */
        if (i == qtdArtistasMus) {
            // Ajeitar essa leitura de strings aqui de um jeito q ele le cada artista e armazena na matriz
            sscanf(m->id_artistas, "%[^;];", id[qtdArtistasMus-1]);
        } else {
            sscanf(m->id_artistas, "%[^|]|", id[qtdArtistasMus-1]);
        }
        printf("%s\n", id[qtdArtistasMus-1]);
        // Varre array artistas para procurar aquele que tem id igual ao verificado
        m->arrayArtistas[contPosicaoArray] = RetornaArtista(as, id[qtdArtistasMus-1]);
        contPosicaoArray++;
    }
}

int RetornaQtdArtistasDaMusica(Musica *m) {
    int i=0, cont=1;

    while (1) {
        if (m->id_artistas[i] == '|') {
            cont++;
        }
        if (m->id_artistas[i] == ';') {
            // printf("%d\n", cont);
            return cont;
        }
        i++;
    }
}