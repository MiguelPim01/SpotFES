#include <stdio.h>
#include <stdlib.h>

#include "tMusicas.h"
#include "tMusica.h"

struct tMusicas {
    tMusica **musicas;
};

tMusicas *CarregaArquivoDeMusicas(FILE *pFile, tMusicas *m)
{
    char linha[2000];
    int espacoAlocado=100, qtdMusicas=0;

    // Aloca espaço para o ponteiro de ponteiro "(tMusica **)musicas"
    m = (tMusicas *)malloc(sizeof(tMusicas));

    // Aloca espaço para os ponteiros que irão apontar para as structs tMusica
    m->musicas = (tMusica **)malloc(espacoAlocado*sizeof(tMusica *));

    while (fscanf(pFile, "%[^\n]\n", linha) == 1)
    {
        // Fazer realocação se necessario
        if (qtdMusicas >= espacoAlocado)
        {
            espacoAlocado = espacoAlocado * 2;
            m->musicas = (tMusica **)realloc(m->musicas, espacoAlocado*sizeof(tMusica *));
        }
        
        // Fazer a leitura da musica
        m->musicas[qtdMusicas] = LeMusica(linha);

        // Incremento na quantidade de musicas
        qtdMusicas++;
    }

    return m;
}