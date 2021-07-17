/*
** EPITECH PROJECT, 2020
** printf_flag.c
** File description:
** printf action put
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_printf.h"
#include "my.h"

int test_match(char c, char *base);
void put_int(int nb, data_t *data);
void put_hexa(unsigned int nb, data_t *data, char *base);
int chec_presicion(int len, data_t *data);
int chec_str_champ(int len, data_t *data);
int chec_signed_champ(int len, data_t *data, int prec, int sign);

int put_p(void *ptr, data_t *data)
{
    long new = (long)ptr;
    int len = nbrlen_base(new, "0123456789abcdef");
    int nb_z = chec_presicion(len, data);
    int champ = chec_signed_champ(len + 2, data, nb_z, 0);

    if (data->sign == 1)
        my_putchar(' ');
    if (data->sign == 2)
        my_putchar('+');
    if (champ < 0)
        nb_z = champ * -1;
    my_putstr("0x");
    for (int i = 0; i < nb_z; i++)
        my_putchar('0');
    my_putnbr_base(new, "0123456789abcdef");
    for (int i = 0; champ + i > 0; i--)
        my_putchar(' ');
    return (0);
}

void put_form(char *str, data_t *data)
{
    int limit = my_strlen(str);
    int champ = 0;

    if (limit > data->prec && data->prec != -1)
        limit = data->prec;
    champ = chec_str_champ(limit, data);
    if (data->sign == 1)
        my_putchar(' ');
    for (int i = 0; i < limit; i++)
        my_putchar(str[i]);
    for (int i = 0; i < champ; i++)
        my_putchar(' ');
}

void spec_put_char(char c, data_t *data)
{
    int zero = 0;

    if (data->champ >= 1)
        zero = data->champ - 1;
    if (data->sens == 1) {
        my_putchar(c);
        for (int i = 0; i < zero; i++)
            my_putchar(' ');
    } else {
        for (int i = 0; i < zero; i++)
            my_putchar(' ');
        my_putchar(c);
    }
}

void put_base(data_t *data, va_list ap)
{
    if (data->comver == 'u')
        put_hexa(va_arg(ap, unsigned int), data, "0123456789");
    if (data->comver == 'o')
        put_hexa(va_arg(ap, unsigned int), data, "01234567");
    if (data->comver == 'x')
        put_hexa(va_arg(ap, unsigned int), data, "0123456789abcdef");
    if (data->comver == 'X')
        put_hexa(va_arg(ap, unsigned int), data, "0123456789ABCDEF");
    if (data->comver == 'b')
        put_hexa(va_arg(ap, unsigned int), data, "01");
}

void put_flag(data_t *data, va_list ap)
{
    if (data->comver == 0)
        return;
    if (test_match(data->comver, "di") == 1)
        put_int(va_arg(ap, int), data);
    put_base(data, ap);
    if (data->comver == 'p')
        put_p(va_arg(ap, void *), data);
    if (data->comver == 's')
        put_form(va_arg(ap, char *), data);
    if (data->comver == 'S')
        my_showstr(va_arg(ap, char *));
    if (data->comver == 'c')
        spec_put_char(va_arg(ap, int), data);
    if (data->comver == '%')
        my_putchar('%');
}
