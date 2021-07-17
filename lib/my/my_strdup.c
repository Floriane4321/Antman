/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** aloc and copi a memori
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *, char const *);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *new = malloc(sizeof(char) * (len + 1));

    new = my_strcpy(new, src);
    return (new);
}
