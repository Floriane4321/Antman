/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** upcae one first caract of letter
*/

char *my_strlowcase(char *str);
int recur_capitalize(char *str);

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    recur_capitalize(str);
    if (*str < 123 && *str > 96)
        *str = *str - 32;
    return (str);
}

int recur_capitalize(char *str)
{
    if (*str == '\0')
        return (0);
    if (*str == ' ' || *str == '-' || *str == '+')
        if (*(str + 1) < 123 && *(str + 1) > 96)
            *(str + 1) = *(str + 1) - 32;
    return (recur_capitalize(str + 1));
}
