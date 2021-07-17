/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** str is only alpha mag
*/

int my_str_isupper(char const *str)
{
    if (*str == '\0')
        return (1);
    if (*str >= 65 && *str <= 90)
        return (my_str_isupper(str + 1));
    return (0);
}
