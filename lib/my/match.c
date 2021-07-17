/*
** EPITECH PROJECT, 2020
** match.c
** File description:
** file for match
*/

int match(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s2 == '*') {
        if (match(s1, s2 + 1) == 1)
            return (1);
        else if (*s1 == '\0')
            return (match(s1, s2 + 1));
        else
            return (match(s1 + 1, s2));
    }
    if (*s1 == '\0' || *s2 == '\0')
        return (0);
    if (*s1 == *s2)
        return (match(s1 + 1, s2 + 1));
    return (0);
}
