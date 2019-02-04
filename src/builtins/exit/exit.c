/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exit
*/

#include "../../../include/my.h"

int my_exit(list_t *list, char **input)
{
    (void)list;
    int ret_value = 0;

    my_printf("exit\n");
    (input[1]) ? (ret_value = my_getnbr(input[1])) : (ret_value = 0);
    exit((uint)ret_value % 256);
    return (0);
}
