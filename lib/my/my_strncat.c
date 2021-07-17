/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** contcat n caract
*/

int my_strlen(char const *);

char *my_strncat(char *dest, char const *src, int nb)
{
    int lend = my_strlen(dest);
    int lens = my_strlen(src);

    for (int i = lend; i != lend + lens && i < nb + lend; i++)
        dest[i] = src[i - lend];
    dest[lend + nb] = '\0';
    return (dest);
}
