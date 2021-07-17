/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reve str
*/

void my_putchar(char c);

int my_strle(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int z = my_strle(str);
    int parity = 0;
    char tmp;

    parity = (z % 2 == 1) ? 1 : 0;
    for (int i = 0; i < (z - parity) / 2; i++) {
        tmp = str[i];
        str[i] = str[z - 1 - i];
        str[z - 1 - i] = tmp;
    }
    return (str);
}
