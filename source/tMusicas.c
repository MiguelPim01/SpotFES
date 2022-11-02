#include <stdio.h>
#include <stdlib.h>

#include "tMusicas.h"
#include "tMusica.h"

struct tMusicas {
    tMusica **musicas;
};

Musicas *CarregaArquivoMusicas(FILE *pFile, Musicas *m)
{
    char linha[2000];
    int espacoAlocado=100, qtdMusicas=0;

    // Aloca espaço para o ponteiro de ponteiro "(Musica **)musicas"
    m = (Musicas *)malloc(sizeof(Musicas));

    // Aloca espaço para os ponteiros que irão apontar para as structs Musica
    m->musicas = (Musica **)malloc(espacoAlocado*sizeof(Musica *));

    while (fscanf(pFile, "%[^\n]\n", linha) == 1)
    {
        // Fazer realocação se necessario
        if (qtdMusicas >= espacoAlocado)
        {
            espacoAlocado = espacoAlocado * 2;
            m->musicas = (Musica **)realloc(m->musicas, espacoAlocado*sizeof(Musica *));
        }
        
        // Fazer a leitura da musica
        m->musicas[qtdMusicas] = LeMusica(linha);

        // Incremento na quantidade de musicas
        qtdMusicas++;
    }

    return m;
}