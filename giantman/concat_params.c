/*
** EPITECH PROJECT, 2020
** concat param
** File description:
** cat param like ch star star to ch star
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *concat_params(int ac, char **av)
{
    int len = 0;
    char *param;

    for (int i = 0; i < ac; i++)
        len = len + my_strlen(av[i]);
    param = malloc(sizeof(char) * (len + 1));
    param = my_strcpy(param, av[0]);
    for (int j = 1; j < ac; j++) {
        my_strcat(param, av[j]);
    }
    return (param);
}
