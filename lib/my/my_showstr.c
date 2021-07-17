/*
** EPITECH PROJECT, 2020
** shostr
** File description:
** sagz
*/

void my_putchar(char c);
int my_strlen(char *str);
int my_putnbr_base(unsigned long nbr, char *base);

void special_put(char c)
{
    my_putchar('\\');
    if (c <= 7)
        my_putchar('0');
    if (c <= 63)
        my_putchar('0');
    my_putnbr_base((int)c, "01234567");
}

int nbrbase_recu(unsigned long nbr, char *base)
{
    int unit;
    unsigned long bas = my_strlen(base);

    if (nbr <= 0)
        return (0);
    unit = nbr % bas;
    nbrbase_recu(nbr / bas, base);
    my_putchar(base[unit]);
    return (0);
}

int my_putnbr_base(unsigned long nbr, char *base)
{
    if (nbr == 0) {
        my_putchar(base[0]);
        return (0);
    }
    return (nbrbase_recu(nbr, base));
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127)
            special_put(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
