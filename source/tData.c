#include <stdio.h>
#include <stdlib.h>

#include "tData.h"

struct tData {
    int dia, mes, ano;
};

Data *InicializaData(int dia, int mes, int ano)
{
    Data *data = (Data *)malloc(sizeof(Data));

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}