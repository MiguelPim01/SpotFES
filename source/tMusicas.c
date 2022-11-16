#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        m->musicas[qtdMusicas] = LeMusica(linha, qtdMusicas+1);

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

void RelacionaArraysMusicasEArtistas(Musicas *m, Artistas *a)
{
    int i;

    for (i = 0; i < m->qtdMusicas; i++)
    {
        AtribuiArtistasAMusica(m->musicas[i], a);
    }
}

void ImprimeMusicasOrdenadas(Musicas *m, int *arrayIndices, int qtdMusicas, FILE *pFileRelatorio)
{
    int i, qtdMusicasSaida, arrayIndicesMusicas[qtdMusicas];

    for (i = 0; i < qtdMusicas; i++)
    {
        arrayIndicesMusicas[i] = arrayIndices[i];
    }

    qtdMusicasSaida = OrdenaPorFrequenciaERetornaQtd(arrayIndicesMusicas, qtdMusicas);

    //Imprime as musicas em ordem
    for (i = 0; i < qtdMusicasSaida; i++)
    {
        ImprimeMusicaRelatorio(m->musicas[arrayIndicesMusicas[i]], pFileRelatorio);
    }
}

int OrdenaPorFrequenciaERetornaQtd(int *arrayIndices, int qtd)
{
    // Matrizes para armazenar as músicas (coluna 0) e frequência (coluna 1)
    int matrizAux[qtd][2], matrizSaida[qtd][2],
    i, j, qtdMusicasSaida, cont, aux;

    // Inicializa matriz 1 com elementos do array de indices e frequencia 0
    for (i = 0; i < qtd; i++)
    {
        matrizAux[i][0] = arrayIndices[i];
        matrizAux[i][1] = 0;
    }

    // Armazena os índices únicos e suas respectivas frequências na matriz 2
    for (i = 0, qtdMusicasSaida = 0; i < qtd; i++)
    {
        if (matrizAux[i][1])
        {
            continue;
        }
        cont = 0;
        for (j = i+1; j < qtd; j++)
        {
            if (matrizAux[i][0] == matrizAux[j][0])
            {
                matrizAux[j][1] = 1;
                cont++;
            }
        }
        matrizSaida[qtdMusicasSaida][0] = matrizAux[i][0];
        matrizSaida[qtdMusicasSaida][1] = cont+1;
        qtdMusicasSaida++;
    }
    qtd = qtdMusicasSaida;

    // Ordena elementos por frequência decrescente
    for (i = 0; i < qtd; i++)
    {
        for (j = i+1; j < qtd; j++)
        {
            if (matrizSaida[i][1] < matrizSaida[j][1])
            {
                aux = matrizSaida[i][0];
                matrizSaida[i][0] = matrizSaida[j][0];
                matrizSaida[j][0] = aux;
            }
        }
    }

    for (i = 0; i < qtd; i++)
    {
        arrayIndices[i] = matrizSaida[i][0];
    }

    return qtd;
}

int RetornaQtdMusicas(Musicas *m)
{
    return m->qtdMusicas;
}

void OrdenaArrayPorDistancia(Musicas *m, float *mediaPlaylist, int *arrayIndicesMusicas) {
    int i, j;
    float distancia1, distancia2, aux;

    for (i = 0; i < m->qtdMusicas; i++)
    {
        distancia1 = CalculaDistancia(m->musicas[i], mediaPlaylist);
        for (j = i+1; j < m->qtdMusicas; j++)
        {
            distancia2 = CalculaDistancia(m->musicas[j], mediaPlaylist);
            if (distancia1 > distancia2)
            {
                aux = arrayIndicesMusicas[i];
                arrayIndicesMusicas[i] = arrayIndicesMusicas[j];
                arrayIndicesMusicas[j] = aux;
            }
        }
    }
}

void AtribuiArrayCaracteristicas(Musicas *m, float *mediaPlaylist, int *indices, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++) {
        AdicionaValoresCaracteristicas(m->musicas[indices[i]], mediaPlaylist);
        for(int i=0; i<8; i++) printf("%.3f \\ ", mediaPlaylist[i]);
    }
}

void ImprimeRecomendacoes(Musicas *m, int *arrayIndicesMusicas, int k)
{
    for (int i = 0; i < k; i++) {
        ImprimeMusica(m->musicas[arrayIndicesMusicas[i]]);
    }
}