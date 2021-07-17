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
list_tree_t *key_crpt(char *file);
void put_bin_to_tree(char *str, list_tree_t *bin);

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

void convert_bin(char *str, int nb, int base, int coun)
{
    if (coun == 8)
        return;
    if (nb >= base) {
        *str = '1';
        convert_bin(str + 1, nb - base, base / 2, coun + 1);
    } else {
        *str = '0';
        convert_bin(str + 1, nb, base / 2, coun + 1);
    }
    return;
}

char *str_bin(char *str, char *more, int oct)
{
    int len = oct;
    int size = len * 8;
    char *new = malloc(sizeof(char) * (2 + size + my_strlen(more)));
    unsigned char test;

    new[size + my_strlen(more) + 1] = '\0';
    for (int i = 0; i < len; i++) {
        test = str[i];
        convert_bin(&new[i * 8], test, 128, 0);
    }
    return (new);
}

void uncompress(char *file, int size)
{
    list_tree_t *tree = key_crpt(file);
    list_tree_t *new = list_tree_copy(tree);
    char *str = NULL;
    int len = 0;

    while (file[len] != '\0')
        len++;
    len++;
    str = my_strdup(&file[len]);
    while (tree->next != NULL) {
        tree = join_noeud(tree);
    }
    while (file[len] != '\0')
        len++;
    len++;
    str = my_strcat(str_bin(&file[len], str, size - len), str);
    put_bin_to_tree(str, tree);
    free(str);
}
