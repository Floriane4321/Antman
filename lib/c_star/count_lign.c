/*
** EPITECH PROJECT, 2020
** count_lign.c
** File description:
** function for count how many lign in a str
*/

int my_lignlen(char *str);

//function return how many \n find
int count_lign(char *str)
{
    int i = 0;
    int lign = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            lign++;
        i++;
    }
    return (lign);
}

//function return how many \n find
// if a lign is not eq to the first return -1
// \0 is not a \n
int count_lign_eq(char *str)
{
    int i = 0;
    int stack = 0;
    int patern = my_lignlen(str);
    int lign = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            lign++;
            if (stack != patern)
                return (-1);
            stack = 0;
        } else
            stack++;
        i++;
    }
    return (lign);
}
