#ifndef _TMUSICAS_H_
#define _TMUSICAS_H_

typedef struct tMusicas tMusicas;

/*
 * Recebe arquivo para leitura e retorna um ponteiro para todas as musicas
 */
tMusicas *CarregaArquivoDeMusicas(FILE *pFile, tMusicas *m);

#endif