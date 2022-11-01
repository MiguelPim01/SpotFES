#include <stdio.h>
#include <stdlib.h>

#include "tArtista.h"

struct tArtista {
    char *id, *generos, *nome;
    int numSeguidores, popularidade;
};