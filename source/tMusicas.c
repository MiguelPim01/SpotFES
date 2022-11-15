#include <stdio.h>
#include <stdlib.h>

#include "tMusicas.h"
#include "tMusica.h"
#include "tArtistas.h"

struct tMusicas {
    Musica **musicas;
    int qtdMusicas;
};

Musicas *CarregaArquivoMusicas(FILE *pFile, Musicas *m)
{
    char linha[5000];
    int espacoAlocado=25, qtdMusicas=0;

    // Aloca espaço para o ponteiro de ponteiro "(Musica **)musicas"
    m = (Musicas *)malloc(sizeof(Musicas));

    // Aloca espaço para os ponteiros que irão apontar para as structs Musica
    m->musicas = (Musica **)malloc(espacoAlocado*sizeof(Musica *));

    while (fscanf(pFile, "%[^\n]\n", linha) == 1)
    {
        // Fazer realocação se necessario
        if (qtdMusicas >= espacoAlocado)
        {
            espacoAlocado *= 2;
            m->musicas = (Musica **)realloc(m->musicas, espacoAlocado*sizeof(Musica *));
        }
        
        // Fazer a leitura da musica
        m->musicas[qtdMusicas] = LeMusica(linha);

        // Incremento na quantidade de musicas
        qtdMusicas++;
    }

    m->qtdMusicas = qtdMusicas;

    return m;
}

void LiberaMusicas(Musicas *m)
{
    // Liberando cada musica separadamente
    int i;
    for (i = 0; i < m->qtdMusicas; i++)
    {
        LiberaMusica(m->musicas[i]);
    }

    // Liberando ponteiros restantes
    free(m->musicas);
    free(m);
}

void ImprimeDadosDasMusicas(Musicas *m)
{
    int i;
    for (i = 0; i < m->qtdMusicas; i++)
    {
        ImprimeMusica(m->musicas[i]);
        printf("\n");
    }
    printf("QTD MUSICAS: %d\n", m->qtdMusicas);
}

void BuscaMusicas(Musicas *m, char *texto)
{
    int i=0;

    printf("################\n");
    printf("Resultado de busca por '%s':\n\n", texto);
    for (i = 0; i < m->qtdMusicas; i++)
    {
        if (ComparaNomeComTexto(m->musicas[i], texto))
        {
            printf("Indice: %d, ", i);
            ImprimeMusica(m->musicas[i]);
        }
    }
    printf("################\n");
}

void BuscaIndiceDaMusica(Musicas *m, int indice)
{
    printf("################\n");
    if (indice >= m->qtdMusicas)
    {
        printf("\nERRO: Indice ultrapassou a quantidade de musicas existentes!\n");
    }
    else
    {
        PrintaDadosDaMusicaEArtistas(m->musicas[indice]);
    }
    printf("################\n");
}

void ImprimeMusicasPorIndices(Musicas *m, int *arrayIndices, int qtdMusicas)
{
    int i;

    for (i = 0; i < qtdMusicas; i++)
    {
        ImprimeMusica(m->musicas[arrayIndices[i]]);
    }
}

void RelacionaArrayDeMusicasEArtistas(Musicas *m, Artistas *a)
{
    int i;

    for (i = 0; i < m->qtdMusicas; i++)
    {
        AtribuiArtistasAMusica(m->musicas[i], a);
    }
}

void RelacionaArraysMusicasEArtistas(Musicas *m, Artistas *as) {
    int i;

    for (i=0; i<m->qtdMusicas; i++) {
        AtribuiArtistasAMusica(m->musicas[i], as);
    }
}