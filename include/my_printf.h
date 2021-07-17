/*
** EPITECH PROJECT, 2020
** printf.h
** File description:
** struct and proto of printf
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

typedef enum step
{
    ATTRIBUT,
    CHAMP,
    PREC,
    TALL,
    COVERT,
    END,
    ECHEC
}step_e;

typedef struct data_s
{
    int marc;
    int comp;
    int sens;
    int sign;
    int champ;
    int prec;
    char tall;
    char comver;
}data_t;

void my_printf(char *str, ...);
#endif
