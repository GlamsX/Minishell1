/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

char *my_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * (size + 1));
    int c = 0;

    if (str == NULL || size < 1)
        return (NULL);
    for (; c != size && str[c] != '\0'; c++)
        new_str[c] = str[c];
    if (str[c] == '\0')
        while (c < size)
            new_str[c++] = '\0';
    new_str[c] = '\0';
    free(str);
    return (new_str);
}

char get_char(int fd)
{
    static char buff[READ_SIZE];
    static char *new_buff;
    static int retsize = 0;
    char c;

    if (retsize == 0) {
        retsize = read(fd, buff, READ_SIZE);
        new_buff = buff;
        if (retsize == 0)
            return (0);
    }
    c = *new_buff;
    new_buff++;
    retsize--;
    return (c);
}

char *read_value(int fd, char *str)
{
    char *buff = malloc(sizeof(char) * 4096);
    int retsize = 0;

    if (fd < 0 || !str)
        return (NULL);
    retsize = read(fd, buff, 4096);
    if (retsize < 1)
        return (NULL);
    buff[retsize] = '\0';
    free(str);
    return (buff);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * (READ_SIZE + 2));
    char c;

    if (fd < 1)
        return (read_value(fd, str));
    if (!str)
        return (NULL);
    c = get_char(fd);
    (c == '\0' || c == '\n') ? str[0] = '\0' : 0;
    for (int i = 0; c != '\n' && c != '\0';) {
        str[i] = c;
        c = get_char(fd);
        i++;
        str[i] = '\0';
        if (i % (READ_SIZE + 1) == 0)
            str = my_realloc(str, i + READ_SIZE + 1);
    }
    if (c == 0)
        return (NULL);
    return (str);
}
