/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

int find_char(char c, char sep, char w)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == sep || c == '\0' || w == c)
        return (0);
    else
        return (1);
}

int calc_size(char const *str, char sep, char sep2)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (find_char(str[i], sep, sep2) == 0)
            nb += 1;
    }
    return (nb);
}

int calc_nb_sep(char const *c, char sep, char sep2)
{
    int nb = 0;

    for (int i = 0; c[i] != '\0'; i++)
        if (find_char(c[i], sep, sep2) == 0)
            nb++;
    return (nb + 1);
}

char **my_str_to_word_array(char *str, char s, char s2)
{
    int j = 0;
    char **result = NULL;

    if (!str)
        return (NULL);
    result = malloc(sizeof(char *) * (calc_size(str, s, s2) + 2));
    for (int k = 0, i = 0; str[i] != '\0'; i++, j++) {
        result[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (; find_char(str[i], s, s2) == 0; i++);
        k = 0;
        for (; str[i] != '\0' && find_char(str[i], s, s2) != 0; i++, k++)
            result[j][k] = str[i];
        result[j][k] = '\0';
        if (str[i] == '\0')
            break;
    }
    result[j] = NULL;
    return (result);
}
