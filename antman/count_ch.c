/*
** EPITECH PROJECT, 2021
** count_ch.c
** File description:
** count ch ocurance
*/

#include "list.h"
#include <stdlib.h>

list_tree_t *list_tre_create(void);

int is_count(char c, list_tree_t *tree)
{
    while (tree != NULL) {
        if (tree->key == c) {
            tree->hz = tree->hz + 1;
            return (0);
        }
        tree = tree->next;
    }
    return (1);
}

list_tree_t *add_new(list_tree_t *tree, char c)
{
    list_tree_t *new = list_tre_create();

    new->key = c;
    new->hz = 1;
    new->next = tree;
    return (new);
}

list_tree_t *count_ch(char *file)
{
    list_tree_t *tree = list_tre_create();

    tree->key = *file;
    tree->hz = 1;
    for (int i = 1; file[i] != '\0'; i++) {
        if (is_count(file[i], tree) == 1)
            tree = add_new(tree, file[i]);
    }
    return (tree);
}
