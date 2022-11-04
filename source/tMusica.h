#ifndef _TMUSICA_H_
#define _TMUSICA_H_

typedef struct tMusica Musica;

/*
 * Faz a leitura e as alocações necessarias para uma musica
 */
Musica *LeMusica(char *buffer);

/*
 * Aloca espaço para as strings contidas em Musica e atribui strings a elas
 */
void FinalizaMusica(Musica *musica, char *id, char *nome, char *artistas, char *id_artistas, char *data);

/*
 * Libera o espaço alocado para uma musica da memoria
 */
void LiberaMusica(Musica *m);

void ImprimeMusica(Musica *musica);

#endif