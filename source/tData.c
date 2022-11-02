#include <stdio.h>
#include <stdlib.h>

#include "tData.h"

struct tData {
    int dia, mes, ano;
};

tData *InicializaData(int dia, int mes, int ano)
{
    tData *data = (tData *)malloc(sizeof(struct tData));

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}