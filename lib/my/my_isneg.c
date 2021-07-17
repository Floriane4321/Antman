/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** say if pos or neg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    my_putchar((n < 0) ? 'N' : 'P');
    return (0);
}
