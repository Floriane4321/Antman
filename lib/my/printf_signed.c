/*
** EPITECH PROJECT, 2020
** printf_signed.c
** File description:
** printf signed conv
*/

#include "my_printf.h"
#include "my.h"

int chec_presicion(int len, data_t *data);
int nbr_len(int nb);

int chec_signed_champ(int len, data_t *data, int prec, int sign)
{
    int plus = 0;

    if (data->sign == 1 || data->sign == 2 || sign == 1)
        plus = 1;
    if (data->champ == -1 || (data->champ - len - prec - plus < 0))
        return (0);
    if (data->sens == 1) {
        return (data->champ - len - prec - plus);
    } else if (data->comp == 1)
        if (data->prec == -1)
            return (-1 * (data->champ - len - prec - plus));
    for (int i = 0; i < data->champ - len - prec - plus; i++)
        my_putchar(' ');
    return (0);
}

int chec_str_champ(int len, data_t *data)
{
    int plus = 0;

    if (data->sign == 1)
        plus = 1;
    if (data->champ == -1 || (data->champ - len - plus < 0))
        return (0);
    if (data->sens == 1)
        return (data->champ - len - plus);
    for (int i = 0; i < data->champ - len - plus; i++)
        my_putchar(' ');
    return (0);
}

void put_int(int nb, data_t *data)
{
    int abs_nb = (nb * nb) / nb;
    int len = nbr_len(abs_nb);
    int sign = (abs_nb != nb) ? 1 : 0;
    int nb_z = chec_presicion(len, data);
    int champ = chec_signed_champ(len, data, nb_z, sign);

    if (data->sign == 1 && sign != 1)
        my_putchar(' ');
    if (data->sign == 2 && sign != 1)
        my_putchar('+');
    if (sign == 1)
        my_putchar('-');
    if (champ < 0)
        nb_z = champ * -1;
    for (int i = 0; i < nb_z; i++)
        my_putchar('0');
    my_put_nbr(abs_nb);
    for (int i = 0; champ + i > 0; i--)
        my_putchar(' ');
}
