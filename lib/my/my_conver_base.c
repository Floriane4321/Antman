/*
** EPITECH PROJECT, 2020
** my_convert_base.c
** File description:
** file for conver a base in a str
*/

#include <stdlib.h>

int my_strlen(char *str);

int nbrlen_base(unsigned long nbr, char *base)
{
    int unit;
    unsigned long bas = my_strlen(base);

    if (nbr < 0)
        return (0);
    if (nbr == 0)
        return (0);
    unit = nbr % bas;
    return (nbrlen_base(nbr / bas, base) + 1);
}

char *conv_recu(unsigned long nbr, char *base, char *new, int len)
{
    int unit;
    unsigned long bas = my_strlen(base);

    if (nbr == 0)
        return (new);
    unit = nbr % bas;
    conv_recu(nbr / bas, base, new, len - 1);
    *(new + len) = base[unit];
    return (new);
}

char *convert_base(unsigned long nbr, char *base)
{
    char *nb;
    int len = nbrlen_base(nbr, base);

    if (nbr != 0) {
        nb = malloc(sizeof(char) * (len + 1));
        nb[len] = '\0';
        return (conv_recu(nbr, base, nb, len - 1));
    }
    nb = malloc(sizeof(char) * 2);
    nb[0] = base[0];
    nb[1] = '\0';
    return (nb);
}
