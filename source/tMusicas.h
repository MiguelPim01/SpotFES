#ifndef _TMUSICAS_H_
#define _TMUSICAS_H_
#include "tArtistas.h"

#include "tArtistas.h"

typedef struct tMusicas Musicas;

/*
 * Recebe arquivo para leitura e retorna um ponteiro para todas as musicas
 */
Musicas *CarregaArquivoMusicas(FILE *pFile, Musicas *m);

/*
 * Libera o espaço alocado para musicas da memoria
 */
void LiberaMusicas(Musicas *m);

/*
 * Imprimir os dados de todas as musicas contidas no vetor alocado de musicas
 */
void ImprimeDadosDasMusicas(Musicas *m);

/*
 * Faz a busca musica a musica de acordo com o texto digitado pelo usuario
 */
void BuscaMusicas(Musicas *m, char *texto);

/*
 * Faz a busca de uma musica dado o seu id e exibe na tela as informações da musica
 */
void BuscaIndiceDaMusica(Musicas *m, int indice);

void ImprimeMusicasPorIndices(Musicas *m, int *arrayIndices, int qtdMusicas);

/*
 * Varre a array de musicas para enviar cada música para outra função que verifica os artistas correspondentes
 */
void RelacionaArraysMusicasEArtistas(Musicas *m, Artistas *as);

int RetornaQtdMusicas(Musicas *m);

void ImprimeMusicasOrdenadas(Musicas *m, int *arrayIndices, int qtdMusicas, FILE *pFileRelatorio);

int OrdenaPorFrequenciaERetornaQtd(int *arrayIndices, int qtd);

void AtribuiArrayCaracteristicas(Musicas *m, float *mediaPlaylist, int *indices, int qtd);

void OrdenaArrayPorDistancia(Musicas *m, float *mediaPlaylist, int *arrayIndicesMusicas);

void ImprimeRecomendacoes(Musicas *m, int *arrayIndicesMusicas, int k);

void RodaMusicaSpotify(Musicas *m, int indiceMusica);

#endif