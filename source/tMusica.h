#ifndef _TMUSICA_H_
#define _TMUSICA_H_

typedef struct tMusica tMusica;

/*
 * Faz a leitura e as alocações necessarias para uma musica
 */
tMusica *LeMusica(char *buffer);

/*
 * Aloca espaço para as strings contidas em tMusica e atribui strings a elas
 */
tMusica *FinalizaMusica(tMusica *musica, char *id, char *nome, char *artistas, char *id_artistas);

#endif