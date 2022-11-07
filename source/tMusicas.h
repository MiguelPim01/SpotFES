#ifndef _TMUSICAS_H_
#define _TMUSICAS_H_

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

#endif