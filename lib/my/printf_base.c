/*
** EPITECH PROJECT, 2020
** printf_base
** File description:
** printf hexa, octal
*/

#include "my_printf.h"
#include "stdlib.h"
#include "my.h"

char *convert_base(unsigned long nbr, char *base);

int chec_presicion(int len, data_t *data)
{
    int prec = data->prec;

    if (prec > len)
        return (prec - len);
    else
        return (0);
}

int chec_hexa_champ(int len, data_t *data, int prec)
{
    int plus = 0;

    if ((data->comver == 'x' || data->comver =='X') && data->marc == 1)
        plus = 2;
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

void marc_handel(data_t *data, int nb_plus)
{
    if (data->marc == 1) {
        if (data->comver == 'x') {
            my_putstr("0x");
        } else if (data->comver == 'X') {
            my_putstr("0X");
        }
        if (data->comver == 'o' && nb_plus == 0) {
            my_putchar('0');
        }
    }
}

void put_hexa(unsigned int nb, data_t *data, char *base)
{
    char *str = convert_base(nb, base);
    int len = my_strlen(str);
    int nb_plus = chec_presicion(len, data);
    int champ = chec_hexa_champ(len, data, nb_plus);

    if (champ < 0)
        nb_plus = champ * -1;
    marc_handel(data, nb_plus);
    for (int i = 0; i < nb_plus; i++)
        my_putchar('0');
    my_putstr(str);
    for (int i = 0; champ + i > 0; i--)
        my_putchar(' ');
    free(str);
}
