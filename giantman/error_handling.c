/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error handling
*/

#include "../include/my.h"
#include "my.h"

int check_type(char *str)
{
    if (match(str, "*.data") == 1)
        return (0);
    return (84);
}

int error_handling(int ac, char *str, char *nbr)
{
    int i = my_getnbr(nbr);
    (void) ac;

    if (i < 1 || i > 3)
        return (84);
    if (check_type(str) != 0)
        return (84);
    return (0);
}
