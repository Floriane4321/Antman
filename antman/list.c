/*
** EPITECH PROJECT, 2021
** list.c
** File description:
** list_file
*/

#include "list.h"
#include "stdlib.h"
#include "my.h"

list_tree_t *list_tre_create(void);

list_tree_t *list_tree_copy(list_tree_t *list)
{
    list_tree_t *new = NULL;
    list_tree_t *save = NULL;

    new = list_tre_create();
    new->key = list->key;
    new->hz = list->hz;
    list = list->next;
    save = new;
    while (list != NULL) {
        new->next = list_tre_create();
        new->next->key = list->key;
        new->next->hz = list->hz;
        new = new->next;
        list = list->next;
    }
    new->next = NULL;
    return (save);
}

void disp_tree(list_tree_t *root)
{
    if (root->b1 == 0)
        return;
    my_put_nbr(root->b1->hz);
    my_putstr(" \t ");
    my_put_nbr(root->b2->hz);
    my_putchar('\n');
    if (root->b1->b1 != NULL) {
        my_putstr("\n B1 tree\n");
        disp_tree(root->b1);
    }else {
        my_put_nbr(root->b1->hz);
        my_putstr("\n-leaf    ->\n");
    }
    if (root->b2->b1 != NULL) {
        my_putstr("\n B2 tree\n");
        disp_tree(root->b2);
    } else {
        my_put_nbr(root->b2->hz);
        my_putstr("\n-leaf    ->\n");
    }
}
