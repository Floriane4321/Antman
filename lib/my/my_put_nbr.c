/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number
*/

#include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int tmp = 0;
    int ret = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            ret = 1;
            nb++;
        }
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10) {
        tmp = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(tmp + 48 + ret);
    } else
        my_putchar(nb + 48);
    return (0);
}
