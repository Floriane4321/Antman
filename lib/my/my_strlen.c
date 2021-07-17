/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** len of str but where is \0
*/

int my_strlen(char const *str)
{
    int p = 0;

    while (str[p] != '\0')
        p++;
    return (p);
}
