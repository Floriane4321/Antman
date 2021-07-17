/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** fonction list basic
*/

#include "../include/mylist.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

list_t *my_params_to_list(int ac, char *const *av)
{
    list_t *element;
    list_t *list = NULL;

    for (int i = ac - 1; i > 0; i--) {
        element = malloc(sizeof(list_t));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}

int my_list_size(list_t *begin)
{
    int i = 0;

    while (begin != NULL) {
        i++;
        begin = begin->next;
    }
    return (i);
}

void put_list(list_t *list)
{
    list_t *tmp = list;

    if (list != NULL) {
        for (int i = 0; i < my_list_size(list); i++) {
            my_putstr(tmp->data);
            my_putchar(10);
            tmp = tmp->next;
        }
    }
}

list_t *create_cell(char *data)
{
    list_t *cell = malloc(sizeof(list_t));

    if (!cell)
        return (NULL);
    cell->data = malloc(sizeof(char) * (my_strlen(data) + 1));
    cell->data[my_strlen(data)] = 0;
    cell->data = my_strncpy(cell->data, data, my_strlen(data));
    cell->next = NULL;
    return (cell);
}

list_t *addcell(list_t *list, int i, char *data)
{
    list_t *now = list;
    list_t *element;
    list_t *cell = create_cell(data);

    if (list == NULL)
        return (cell);
    element = now->next;
    if (i < 0 || my_list_size(list) <= i)
        return (NULL);
    if (i == 0) {
        cell->next = list;
        return (cell);
    }
    for (int j = 0; j < i; j++) {
        element = now;
        now = now->next;
    }
    element->next = cell;
    cell->next = now;
    return (list);
}
