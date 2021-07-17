/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy a str for n caract
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    int i = 0;

    for (i = 0; str[i] != '\0' && i < n; i++)
        dest[i] = str[i];
    dest[n] = '\0';
    return (dest);
}
