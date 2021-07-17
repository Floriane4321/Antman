/*
** EPITECH PROJECT, 2020
** parcing_str.c
** File description:
** function for parc a str
*/

#include "my_printf.h"
#include "my.h"

int nbr_len(long nbr);

int test_match(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++)
        if (c == base[i])
            return (1);
    return (0);
}

step_e t_pat_att(data_t *data, char c, step_e s)
{
    switch (c) {
    case ('#'):
        data->marc = 1;
        return (s);
    case ('0'):
        data->comp = 1;
        return (s);
    case ('-'):
        data->sens = 1;
        return (s);
    case ('+'):
        data->sign = 2;
        return (s);
    case (' '):
        if (data->sign == 0)
            data->sign = 1;
        return (s);
    }
    return (s + 1);
}

int champ_handel(data_t *data, char *str, int who)
{
    int nb = 0;

    if (test_match(str[0], "0123456789") == 0)
        return (0);
    nb = my_getnbr(str);
    if (who == 1)
        data->champ = nb;
    else
        data->prec = nb;
    return (nbr_len(nb));
}

int par_nbr_manager(data_t *data, char *str, enum step s)
{
    int i = 0;

    i = i + champ_handel(data, &str[i], 1);
    if (str[i] == '.') {
        i = i + champ_handel(data, &str[i + 1], 0);
        i++;
    }
    return (i);
}

step_e t_pat(data_t *data, char c, step_e s, char *base)
{
    if (test_match(c, base) == 1) {
        return (s);
    } else
        return (s + 1);
}
