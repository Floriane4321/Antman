/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** love the nbr
*/

int rec_ct(char const *str);
int rec_get(char const *str, int nb, int ng);

int is_num(char c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int neg = 0;

    if (str[0] == '0' && str[1] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_sign(str[i]) == 1) {
            if (str[i] == '-')
                neg++;
            continue;
        }
        if (is_num(str[i]) == 0)
            return (0);
        if (is_num(str[i]) == 1) {
            if (rec_ct(&str[i]) > 10)
                return (0);
            return (rec_get(&str[i], rec_ct(&str[i]), neg));
        }
    }
    return (0);
}

int rec_ct(char const *str)
{
    if (str[1] == '\0' || is_num(str[1]) == 0)
        return (0);
    return (rec_ct(str + 1) + 1);
}

int rec_get(char const *str, int nb, int ng)
{
    int tmp = 0;
    int sign = 1;

    if (ng % 2 == 1)
        sign = (-1);
    if (nb == 0)
        return ((str[nb] - 48) * sign);
    tmp = rec_get(str, nb - 1, ng);
    if (sign == 1) {
        if (tmp * 10 + (str[nb] - 48) < 0)
            return (0);
    } else
        if (tmp * 10 - (str[nb] - 48) > 0)
            return (0);
    tmp = (tmp * 10) + (str[nb] - 48) * sign;
    return (tmp);
}
