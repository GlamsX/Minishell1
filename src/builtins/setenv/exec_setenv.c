/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exec_setenv
*/

#include "../../../include/my.h"

char *concat_elem(char *elem, char *value)
{
    int i = 0;

    for (; elem[i] != '='; i++);
    i += 1;
    elem[i] = '\0';
    elem = my_strcat(elem, value);
    return (elem);
}

void change_value_2(char *elem, char *value, list_t *list, int size)
{
    elem_t *elems = list->front;
    char **tab = get_new_env(list);

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strncmp(tab[i], elem, size) == 0) {
            tab[i] = concat_elem(elem, value);
            break;
        }
    while (elems) {
        pop_front(list);
        elems = elems->next;
    }
    stock_env(list, tab);
    free(tab);
}

void change_value(char *elem, char *value, list_t *list, int size)
{
    elem_t *first = list->front;
    elem_t *end = list->back;

    if (my_strncmp(elem, first->data, size) == 0) {
        pop_front(list);
        push_front(list, concat_elem(elem, value));
        return;
    }
    if (my_strncmp(elem, end->data, size) == 0) {
        pop_back(list);
        push_back(list, concat_elem(elem, value));
        return;
    }
    change_value_2(elem, value, list, size);
}

int do_setenv_2(list_t *list, char *name, char *value)
{
    elem_t *elem = list->front;
    int size = 0;

    while (elem) {
        if (my_strncmp(elem->data, name, my_strlen(name)) == 0) {
            size = my_strlen(elem->data);
            change_value(elem->data, value, list, size);
            return (0);
        }
        elem = elem->next;
    }
    name = my_strcat(name, "=");
    name = my_strcat(name, value);
    push_back(list, name);
    return (0);
}
