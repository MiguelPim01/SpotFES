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

void ImprimeDadosDasMusicas(Musicas *m);

#endif