/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** list hearder
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list_s
{
    char *word;
    int hit;
    struct list_s *next;
}list_t;

typedef struct list_tree_s
{
    struct list_tree_s *b1;
    struct list_tree_s *b2;
    struct list_tree_s *next;
    int hz;
    char key;   
}list_tree_t;

typedef struct count_word_s
{
    struct list_s *word;
    int nb;
    struct list_tree_s *t_bin;
}count_word_t;

#endif
