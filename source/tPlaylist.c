#include <stdio.h>
#include <stdlib.h>

#include "tPlaylist.h"
#include "tMusicas.h"

struct tPlaylist {
    char *nome;
    int *indicesDasMusicas;
};