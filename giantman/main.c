/*
** EPITECH PROJECT, 2021
** main
** File description:
** main hufman
*/

#include <stdio.h>

char *reading_map(char const *path, int *len);
void uncompress(char *file, int size);
int error_handling(int ac, char *str, char *nbr);

int main(int ac, char **av)
{
    char *buf;
    int size = 1;

    if (ac != 3)
        return (84);
    if (error_handling(ac, av[1], av[2]) == 84)
        return (84);
    buf = reading_map(av[1], &size);
    if (size == 0)
        return (0);
    if (buf == NULL)
        return (84);
    uncompress(buf, size);
    return (0);
}
