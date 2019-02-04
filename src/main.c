/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include <signal.h>
#include "../include/my.h"

void display_prompt(void)
{
    char cwd[4096];

    if (getcwd(cwd, 4096) == NULL)
        exit(84);
    my_printf("%s$ ", cwd);
}

void sig_handler(int signum)
{
    if (signum == SIGINT) {
        write(1, "\n", 1);
        display_prompt();
    }
}

void add_elem_vars(list_t *list)
{
    char *path1 =
    "PATH=/home/la-montagne/bin:/home/la-montagne/.local/bin:/usr/local/sbin:";
    char *path2 =
    "/usr/local/bin:/usr/sbin:/usr/bin:/sbin:";
    char *path3 = "/bin:/usr/games:/usr/local/games:/snap/bin";
    char *path = my_strcat(path1, path2);
    char *term = "TERM=xterm-256color";
    char *pwd = malloc(sizeof(char) * 4096);

    path = my_strcat(path, path3);
    pwd = getcwd(pwd, 4096);
    push_back(list, path);
    push_back(list, term);
    push_back(list, my_strcat("PWD=", pwd));
}

int prompt(list_t *list)
{
    int fd = 0;
    int i = 0;
    char *str = NULL;

    while (1) {
        signal(SIGINT, sig_handler);
        signal(12, sig_handler);
        if (isatty(0))
            display_prompt();
        str = get_next_line(fd);
        if (str == NULL) {
            free(str);
            return (i);
        }
        i = execution(str, list);
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
        if (list.front == NULL)
            add_elem_vars(&list);
        i = prompt(&list);
    }
    return (i);
}
