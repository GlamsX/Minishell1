/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_env
*/

#include "../../../include/my.h"

int my_env(list_t *list, char **input)
{
    (void)input;
    elem_t *elem = list->front;

    while (elem) {
        my_printf("%s\n", elem->data);
        elem = elem->next;
    }
    return (0);
}
