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

#endif