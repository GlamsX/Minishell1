/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** [enter description here]
*/

#include "../../../include/my.h"

int check_first(char *str)
{
    if (!(str[0] >= 'a' && str[0] <= 'z') &&
        !(str[0] >= 'A' && str[0] <= 'Z')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' &&
            str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9')) {
            my_printf("setenv: Variable name must contain alphanumeric");
            my_printf(" characters.\n");
            return (1);
        } else
            continue;
    }
    return (0);
}

int do_setenv(list_t *list, char **input)
{
    char *name = input[1];
    char *value = (!input[2]) ? (value = "") : (value = input[2]);

    if (check_first(name) == 0)
        return (do_setenv_2(list, name, value));
    else
        return (1);
}

int my_setenv(list_t *list, char **input)
{
    if (!input[1])
        return (my_env(list, input));
    else if (strlen_tab(input) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    } else
        return (do_setenv(list, input));
}
