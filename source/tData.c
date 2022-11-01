#include "tData.h"

struct Data {
    int dia, mes, ano;
};

Data_pt LeData(char *buffer, Data_pt data)
{
    sscanf(buffer, "%d-%d-%d;", &data->ano, &data->mes, &data->dia);

    return data;
}

Data_pt AlocaData()
{
    Data_pt pt = (Data_pt)malloc(sizeof(Data));

    return pt;
}