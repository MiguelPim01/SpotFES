#include "tMusica.h"

struct Musica {
    Artista_pt * ArrayArtistas;
    Data_pt ptData;
    int qtdArtistas, duracao, popularity, explicit, mode, time_signature;
    float tempo, danceability, energy, loudness, speechness, acoustiness, instrumentalness, liveness, valence;
    char *id, *nome;
};