/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../../include/my.h"

void pop_elem(list_t *list, elem_t *elem)
{
    if (list && elem) {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        list->size--;
    }
}

void pop_back(list_t *list)
{
    if (list->back != NULL) {
        list->back = list->back->prev;
        list->back->next = NULL;
        list->size--;
    }
    if (list->back != NULL && list->size == 1)
        init_list(list);
}

void pop_front(list_t *list)
{
    if (list->front != NULL) {
        list->front = list->front->next;
        list->front->prev = NULL;
        list->size--;
    }
    if (list->size == 1)
        init_list(list);
}

void init_list(list_t *list)
{
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
}

elem_t *create_new_elem(char *data)
{
    elem_t *elem = malloc(sizeof(elem_t));

    if (data == NULL)
        return (NULL);
    if (elem != NULL) {
        elem->data = data;
        elem->prev = NULL;
        elem->next = NULL;
    }
    return (elem);
}
