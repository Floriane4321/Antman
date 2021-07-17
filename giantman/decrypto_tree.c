/*
** EPITECH PROJECT, 2021
** decripto.c
** File description:
** decrypting data
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

list_tree_t *list_tre_create(void);

int crpt_sub(int status, list_tree_t *new, char *file)
{
    if (status == 2) {
        new->hz = my_getnbr(file);
        status = 0;
    }
    if (status == 1) {
        new->key = *file;
        status = 2;
    }
    if (*file == ':' && status == 0) {
        status = 1;
    }
    return (status);
}

list_tree_t *key_crpt(char *file)
{
    list_tree_t *new = list_tre_create();;
    list_tree_t *tmp = new;
    int status = 0;

    for (int i = 0; file[i + 1] != '\0'; i++) {
        status = crpt_sub(status, new, &file[i]);
        if (file[i] == ':' && status == 1) {
            new->next = list_tre_create();
            new = new->next;
        }
    }
    new = tmp;
    tmp = tmp->next;
    free(new);
    return (tmp);
}

void put_bin_to_tree(char *str, list_tree_t *bin)
{
    list_tree_t *next = bin;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0')
            next = next->b1;
        if (str[i] == '1')
            next = next->b2;
        if (next->b1 == NULL) {
            my_putchar(next->key);
            next = bin;
        }
    }
}
