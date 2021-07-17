/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** find a prime who is highter than a nbr
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (2);
    if (my_is_prime(nb) == 1)
        return (nb);
    if (nb % 2 == 0)
        return (my_find_prime_sup(nb + 1));
    else
        return (my_find_prime_sup(nb + 2));
}
