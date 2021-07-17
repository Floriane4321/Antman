/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** str is only alpha
*/

int my_str_isnum(char const *str)
{
    if (*str == '\0')
        return (1);
    if (*str >= 48 && *str <= 57)
        return (my_str_isnum(str + 1));
    return (0);
}
