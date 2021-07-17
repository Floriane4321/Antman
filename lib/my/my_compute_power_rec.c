/*
** EPITECH PROJECT, 2020
** my_power_rec
** File description:
** power recurciv
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (my_compute_power_rec(nb, p - 1) * nb);
}
