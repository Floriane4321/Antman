/*
** EPITECH PROJECT, 2020
** utilyti.c
** File description:
** usfull function
*/

int my_lignlen(char *str)
{
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    return (i);
}
