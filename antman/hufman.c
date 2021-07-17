/*
** EPITECH PROJECT, 2021
** huffman
** File description:
** binnary tree create
*/

#include "list.h"
#include "my.h"
#include <stdlib.h>

void disp_tree(list_tree_t *root);
list_tree_t *count_word(char *str);
list_tree_t *list_tre_create(void);
list_tree_t *list_tree_copy(list_tree_t *list);
list_tree_t *count_ch(char *file);
char *bit_str(char *file, list_tree_t *bin, list_tree_t *ref);

list_tree_t *get_mini(list_tree_t *tree)
{
    list_tree_t *old = NULL;
    list_tree_t *tmp = tree;

    while (tree->next != NULL) {
        if (tree->next->hz < tmp->hz) {
            old = tree;
            tmp = tree->next;
        }
        tree = tree->next;
    }
    if (old == NULL)
        return (NULL);
    old->next = old->next->next;
    return (tmp);
}

list_tree_t *join_noeud(list_tree_t *tree)
{
    list_tree_t *first = get_mini(tree);
    list_tree_t *second;
    list_tree_t *root = list_tre_create();

    if (first == NULL) {
        first = tree;
        tree = tree->next;
    }
    second = get_mini(tree);
    if (second == NULL) {
        second = tree;
        tree = tree->next;
    }
    root->next = tree;
    root->b1 = first;
    root->b2 = second;
    root->hz = root->b1->hz + root->b2->hz;
    return (root);
}

void put_binkey(list_tree_t *tree)
{
    while (tree != NULL) {
        my_putchar(':');
        my_putchar(tree->key);
        my_put_nbr(tree->hz);
        tree = tree->next;
    }
    my_putchar(':');
    my_putchar('\0');
}

void put_cripted(char *binary)
{
    int len = my_strlen(binary);
    int ch = 0;
    char tab[8] = "}@ }\b}}}";
    int i = 0;
    int ref = 0;

    tab[0] = 128;
    tab[3] = 16;
    tab[5] = 4;
    tab[6] = 2;
    tab[7] = 1;
    ref = len % 8;
    my_putstr(binary + len - ref);
    my_putchar('\0');
    while (i < len - ref) {
        for (int coun = 0; coun < 8; coun++, i++)
            ch = ch + (binary[i] - 48) * tab[coun];
        my_putchar(ch);
        ch = 0;
    }
}

void tree_bin(char *file)
{
    list_tree_t *tree = count_ch(file);
    list_tree_t *new = list_tree_copy(tree);
    char *str = NULL;

    while (tree->next != NULL) {
        tree = join_noeud(tree);
    }
    str = bit_str(file, tree, new);
    put_binkey(new);
    put_cripted(str);
    free(str);
}
