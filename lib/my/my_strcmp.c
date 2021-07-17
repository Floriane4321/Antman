/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** compar two string
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (0);
    if (*s1 == '\0' || *s1 < *s2)
        return (-1);
    if (*s2 == '\0' || *s1 > *s2)
        return (1);
    return (my_strcmp(s1 + 1, s2 + 1));
}
