/*
** EPITECH PROJECT, 2021
** crypto_tree.c
** File description:
** antman with binary tree
*/

#include "list.h"
#include "my.h"
#include "stdlib.h"

char *concat_params(int ac, char **av);

int search_ref(char c, list_tree_t *ref)
{
    while (ref != NULL) {
        if (ref->key == c)
            return (ref->hz);
        ref = ref->next;
    }
    return (-1);
}

int scearch_deep(char c, int hz, list_tree_t *bin)
{
    int count = 0;

    if (bin->hz < hz)
        return (0);
    if (bin->b1 == NULL) {
        if (bin->hz == hz && bin->key == c)
            return (1);
        else
            return (0);
    }
    if (hz <= bin->b1->hz && count == 0)
        count = scearch_deep(c, hz, bin->b1);
    if (hz <= bin->b2->hz && count == 0)
        count = scearch_deep(c, hz, bin->b2);
    if (count != 0)
        return (count + 1);
    return (count);
}

int generat_binch(char *str, char c, int hz, list_tree_t *bin)
{
    if (bin->hz < hz)
        return (0);
    if (bin->key != c && bin->b1 == NULL)
        return (0);
    if (bin->hz == hz && bin->key == c)
        return (1);
    if (generat_binch(str + 1, c, hz, bin->b1) == 1) {
        *str = '0';
        return (1);
    }
    if (generat_binch(str + 1, c, hz, bin->b2) == 1) {
        *str = '1';
        return (1);
    }
    return (0);
}

char *tree_reading(char c, list_tree_t *bin, list_tree_t *ref)
{
    int hz = search_ref(c, ref);
    int deep = scearch_deep(c, hz, bin);
    char *binary = malloc(sizeof(char) * deep);

    generat_binch(binary, c, hz, bin);
    binary[deep - 1] = '\0';
    return (binary);
}

char *bit_str(char *file, list_tree_t *bin, list_tree_t *ref)
{
    char *str = NULL;
    int len = my_strlen(file);
    char **allch = malloc(sizeof(char *) * (1 + len));

    for (int i = 0; i < len ; i++)
        allch[i] = tree_reading(file[i], bin, ref);
    str = concat_params(len, allch);
    return (str);
}
