#ifndef _TMUSICA_H_
#define _TMUSICA_H_
#include "tArtistas.h"

#include "tArtistas.h"

typedef struct tMusica Musica;

/*
 * Faz a leitura e as alocações necessarias para uma musica
 */
Musica *LeMusica(char *buffer, int contMusicas);

/*
 * Aloca espaço para as strings contidas em Musica e atribui strings a elas
 */
void FinalizaMusica(Musica *musica, char *id, char *nome, char *artistas, char *id_artistas, char *data);

/*
 * Libera o espaço alocado para uma musica da memoria
 */
void LiberaMusica(Musica *m);

/*
 * Imprime dados da musica
 */
void ImprimeMusica(Musica *musica);

/*
 * Se o texto estiver no nome da musica o valor retornado é 1, caso contrario é 0
 */
int ComparaNomeComTexto(Musica *musica, char *texto);

/*
 * Se os id's digitado e da musica forem iguais, funcao retorna 1, caso contrario retorna 0
 */
int ComparaIdComTexto(Musica *musica, char *texto);

/*
 * Atribui os ponteiros de artista a suas devidas musicas
 */
void AtribuiArtistasAMusica(Musica *musica, Artistas *a);

/*
 * Retorna quantidade de artistas de uma musica
 */
int RetornaQtdArtistasDaMusica(Musica *m);

void AdicionaValoresCaracteristicas(Musica *m, float *mediaPlaylist);

float CalculaDistancia(Musica *m, float *mediaPlaylist);

void PrintaDadosDaMusicaEArtistas(Musica *musica);

void ImprimeTudoDaMusica(Musica *musica);

void ImprimeMusicaRelatorio(Musica *m, FILE *pFileRelatorio);

char *ObtemIdMusica(Musica *musica);

#endif