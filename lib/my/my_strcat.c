/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concat param
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int lend = my_strlen(dest);
    int lens = my_strlen(src);

    for (int i = lend; i != lend + lens; i++)
        dest[i] = src[i - lend];
    dest[lend + lens] = '\0';
    return (dest);
}
