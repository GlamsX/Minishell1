/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** utils
*/

#include "../../include/my_printf.h"

char *my_getstr(int nb)
{
    int size = 0;
    int j = nb;
    char *str;

    for (; j > 0; size++)
        j /= 10;
    str = malloc(sizeof(*str) * (size + 1));
    str[size] = '\0';
    while (size--) {
        str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}

char *my_getstr_long(long nb)
{
    long size = 0;
    long j = nb;
    char *str;

    for (; j > 0; size++)
        j /= 10;
    str = malloc(sizeof(*str) * (size + 1));
    str[size] = '\0';
    while (size--) {
        str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}

char *my_getstr_long_long(long long nb)
{
    long long size = 0;
    long long j = nb;
    char *str;

    for (; j > 0; size++)
        j /= 10;
    str = malloc(sizeof(*str) * (size + 1));
    str[size] = '\0';
    while (size--) {
        str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}

char *nb_space(char *str, int i)
{
    char *nb_space = malloc(sizeof(char) * (calc_nb_nbrs(str, i) + 2));
    int j = 0;

    if (str[i] == '.')
        i += 1;
    for (; check_nbrs(str[i]) == 0; i++) {
        nb_space[j] = str[i];
        j++;
    }
    nb_space[j] = '\0';
    return (nb_space);
}
