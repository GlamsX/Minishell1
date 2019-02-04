/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** unsetenv
*/

#include "../../../include/my.h"

int strlen_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    for (; tab[i] != NULL; i++);
    return (i);
}

void pop_all_2(elem_t *elem, char *to_pop, list_t *list)
{
    elem_t *end = list->back;

    while (elem != end) {
        if (my_strncmp(elem->data, to_pop, my_strlen(to_pop)) == 0) {
            pop_elem(list, elem);
            return;
        }
        elem = elem->next;
    }
}

void pop_all(list_t *list, char *to_pop)
{
    elem_t *elem = list->front;
    elem_t *end = list->back;
    int size = my_strlen(to_pop);

    if (my_strncmp(elem->data, to_pop, size) == 0) {
        pop_front(list);
        return;
    }
    if (my_strncmp(end->data, to_pop, size) == 0) {
        pop_back(list);
        return;
    }
    elem = elem->next;
    pop_all_2(elem, to_pop, list);
}

void do_unsetenv(list_t *list, char **tab)
{
    for (int i = 1; tab[i] != NULL; i++)
        pop_all(list, tab[i]);
}

int my_unsetenv(list_t *list, char **input)
{
    if (!input || strlen_tab(input) < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    } else
        do_unsetenv(list, input);
    return (0);
}
