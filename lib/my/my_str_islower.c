/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** str is only alpha lower
*/

int my_str_islower(char const *str)
{
    if (*str == '\0')
        return (1);
    if (*str >= 97 && *str <= 122)
        return (my_str_islower(str + 1));
    return (0);
}
