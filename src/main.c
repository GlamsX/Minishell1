/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

void display_prompt(char cwd[4096])
{
    if (getcwd(cwd, 4096) == NULL)
        exit(84);
    my_printf("%s$ ", cwd);
}

int prompt(list_t *list)
{
    int fd = 0;
    int i = 0;
    char *str = NULL;
    char cwd[4096];

    while (1) {
        if (isatty(0))
            display_prompt(cwd);
        str = get_next_line(fd);
        if (str == NULL)
            return (i);
        i = execution(str, list, 0);
        free(str);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    list_t list;
    int i = 0;

    if (av != NULL && ac == 1) {
        init_list(&list);
        stock_env(&list, env);
        i = prompt(&list);
        free_list(&list);
    }
    return (i);
}
