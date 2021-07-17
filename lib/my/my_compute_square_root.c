/*
** EPITECH PROJECT, 2020
** compute_squar_root
** File description:
** squarre root calc
*/

int my_compute_square_root(int nb)
{
    int count = 1;
    int i = 1;

    if (nb <= 0)
        return (0);
    while (1) {
        count = i * i;
        if (count > nb)
            return (0);
        if (count == nb)
            return (i);
        i++;
    }
    return (0);
}
