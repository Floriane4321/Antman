/*
** EPITECH PROJECT, 2021
** main
** File description:
** main hufman
*/

#include <stdio.h>

char *reading_map(char const *path, int *i);
int error_handling(int ac, char *str, char *nbr);
void tree_bin(char *file);

int main(int ac, char **av)
{
    char *buf;
    int i = 1;

    if (ac != 3)
        return (84);
    if (error_handling(ac, av[1], av[2]) == 84)
        return (84);
    buf = reading_map(av[1], &i);
    if (i == 0)
        return (0);
    if (buf == NULL)
        return (84);
    tree_bin(buf);
    return (0);
}
