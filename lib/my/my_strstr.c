/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** scearch str in a str
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    if (*str == '\0')
        return (NULL);
    if (*to_find == '\0')
        return (str);
    if (*str == *to_find)
        for (int i = 0; *(to_find + i) == *(str + i); i++)
            if (*(to_find + i + 1) == '\0')
                return (str);
    return (my_strstr(str + 1, to_find));
}
