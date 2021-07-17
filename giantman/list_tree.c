/*
** EPITECH PROJECT, 2021
** list.c
** File description:
** chain list main funciton
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list_tree_t *list_tre_create(void)
{
    list_tree_t *new = malloc(sizeof(struct list_tree_s));

    new->next = NULL;
    new->b1 = NULL;
    new->b2 = NULL;
    new->key = 0;
    new->hz = 0;
    return (new);
}

list_tree_t *add_list_tre(list_tree_t *list, list_tree_t *cell)
{
    cell->next = list;
    return (cell);
}

list_tree_t *swap_cell(list_tree_t *curent)
{
    list_tree_t *next = curent->next;

    curent->next = next->next;
    next->next = curent;
    return (next);
}
