/*
** EPITECH PROJECT, 2020
** data_function.c
** File description:
** function prime of data
*/

#include <stdlib.h>
#include "my_printf.h"

data_t *creat_data(void)
{
    data_t *data = malloc(sizeof(data_t) * 1);

    data->marc = 0;
    data->comp = 0;
    data->sens = 0;
    data->sign = 0;
    data->champ = -1;
    data->prec = -1;
    data->tall = 0;
    data->comver = 0;
    return (data);
}

void reset_data(data_t *data)
{
    data->marc = 0;
    data->comp = 0;
    data->sens = 0;
    data->sign = 0;
    data->champ = -1;
    data->prec = -1;
    data->tall = 0;
    data->comver = 0;
}

void destroy_data(data_t **data)
{
    free(*data);
    data = NULL;
}
