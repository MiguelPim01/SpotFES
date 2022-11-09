CC=gcc
CFLAGS=-lm -g -Wall

DEPS=main.c tArtista.c tMusica.c tPlaylist.c tMusicas.c tArtistas.c tPlaylists.c

prog: $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o ../objects/$@ $^ $(CFLAGS)