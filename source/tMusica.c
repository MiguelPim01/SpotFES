#include "tMusica.h"

struct Musica {
    Artista_pt * ArrayArtistas;
    Data_pt ptData;
    int qtdArtistas, duracao_ms, popularity, explicit, mode, time_signature, key;
    float tempo, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence;
    char *id, *nome, *artistas, *id_artistas;
};

Musica_pt *CarregaFileMusicas(FILE *pFileMusicas, Musica_pt *ArrayMusicas)
{
    int EspacoMusicas=100, qtdMusicas=0;
    char linha[1000]; // Armazena linha por linha do arquivo

    // Alocando espaço inicial na memoria para array de musicas
    ArrayMusicas = (Musica_pt *)malloc(EspacoMusicas*sizeof(Musica_pt));

    while (fscanf(pFileMusicas, "%[^\n]\n", linha) == 1)
    {
        // Fazer a realocação de memoria se necessario
        if (qtdMusicas >= EspacoMusicas)
        {
            EspacoMusicas = EspacoMusicas * 2;
            ArrayMusicas = (Musica_pt *)realloc(ArrayMusicas, EspacoMusicas*sizeof(Musica_pt));
        }

        //Fazer malloc para a musica a ser lida
        ArrayMusicas[qtdMusicas] = (Musica_pt)malloc(sizeof(Musica));

        // Fazer a leitura do arquivo
        ArrayMusicas[qtdMusicas] = LeMusica(ArrayMusicas[qtdMusicas], linha);

        // Incrementa a quantidade de musicas
        qtdMusicas++;
    }

    return ArrayMusicas;
}

Musica_pt LeMusica(Musica_pt mus, char *buffer)
{
    char nome[50], id[22], artistas[100], id_artistas[200];
    Data *data;
    
    // Leitura da linha contendo a musica
    sscanf(buffer, "%[^;];", id);
    sscanf(buffer, "%[^;];", nome);
    sscanf(buffer, "%d;", mus->popularity);
    sscanf(buffer, "%d;", mus->duracao_ms);
    sscanf(buffer, "%d;", mus->explicit);
    sscanf(buffer, "%[^;];", artistas);
    sscanf(buffer, "%[^;];", id_artistas);
    data = LeData(buffer, data);
    sscanf(buffer, "%f;", mus->danceability);
    sscanf(buffer, "%f;", mus->energy);
    sscanf(buffer, "%d;", mus->key);
    sscanf(buffer, "%f;", mus->loudness);
    sscanf(buffer, "%d;", mus->mode);
    sscanf(buffer, "%f;", mus->speechiness);
    sscanf(buffer, "%f;", mus->acousticness);
    sscanf(buffer, "%f;", mus->instrumentalness);
    sscanf(buffer, "%f\n", mus->liveness);

    // Alocar variaveis restantes
    int tam=0;

    mus->id = (char *)malloc(TAM_ID*sizeof(char)+1); // Alocando o id
    id[TAM_ID] = '\0';

    tam = TamanhoString(nome);
    nome[tam] = '\0';
    mus->nome = (char *)malloc(tam*sizeof(char)+1); // Alocando o nome

    tam = TamanhoString(artistas);
    artistas[tam] = '\0';
    mus->artistas = (char *)malloc(tam*sizeof(char)+1); // Alocando artistas

    tam = TamanhoString(id_artistas);
    id_artistas[tam] = '\0';
    mus->id_artistas = (char *)malloc(tam*sizeof(char)+1); // Alocando id artistas

    mus->ptData = AlocaData(); // Alocando data
    *(mus->ptData) = *data;

    strcpy(mus->id, id);
    strcpy(mus->nome, nome);
    strcpy(mus->artistas, artistas);
    strcpy(mus->id_artistas, id_artistas);

    return mus;
}

static int TamanhoString(char *str)
{
    int i=0;

    while (str[i] != ';')
    {
        i++;
    }

    return i;
}