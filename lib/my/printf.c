/*
** EPITECH PROJECT, 2020
** printf.c
** File description:
** file of printf main
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_getnbr(char *str);
step_e if_flag(step_e s, data_t *data, char c);
int champ_handel(data_t *data, char *str, int who);
data_t *creat_data(void);
void reset_data(data_t *data);
void destroy_data(data_t **data);
step_e t_pat(data_t *data, char c, step_e s, char *base);
step_e t_pat_att(data_t *data, char c, step_e s);
int test_match(char c, char *base);
void put_flag(data_t *data, va_list ap);
int par_nbr_manager(data_t *data, char *str, enum step s);

int par_return(enum step s, int i)
{
    if (s == END)
        return (i);
    if (s == ECHEC)
        my_putchar('%');
    return (0);
}

int nbr_len(long nbr)
{
    int resu = 0;

    if (nbr == 0)
        return (1);
    while (nbr >= 0) {
        nbr = nbr / 10;
        if (nbr == 0)
            return (resu + 1);
        resu++;
    }
    return (resu);
}

step_e if_flag(step_e s, data_t *data, char c)
{
    int result = 0;

    switch (s) {
    case (ATTRIBUT):
        return (t_pat_att(data, c, s));
    case (TALL):
        return (t_pat(data, c, s, "hljzt"));
    case (COVERT):
        if (test_match(c, "%diouxXpsSbc") == 1) {
            data->comver = c;
            return (END);
        } else
            return (ECHEC);
    }
    return (ECHEC);
}

int flag_manager(char *str, va_list ap, data_t *data)
{
    enum step s = ATTRIBUT;
    int i = 1;
    enum step old = 0;

    while (str[i] != '\0' && (s != END && s != ECHEC)) {
        if (s == CHAMP) {
            i = i + par_nbr_manager(data, &str[i], s);
            s = s + 2;
        }
        s = if_flag(s, data, str[i]);
        if (old == s)
            i++;
        old = s;
    }
    put_flag(data, ap);
    return (par_return(s, i));
}

void my_printf(char *str, ...)
{
    va_list ap;
    int tmp = 0;
    data_t *data = (data_t *)creat_data();

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        tmp = 0;
        if (str[i] == '%') {
            reset_data(data);
            tmp = flag_manager(str + i, ap, data);
        } else
            my_putchar(str[i]);
        i = i + tmp;
    }
    va_end(ap);
    destroy_data(&data);
}
