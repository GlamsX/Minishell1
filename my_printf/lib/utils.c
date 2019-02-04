/*
** EPITECH PROJECT, 2018
** prindtf
** File description:
** calc size of string
*/

#include "../../include/my_printf.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    if (*str == '\0')
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}

int convert_to_octal(int nb)
{
    int x = 0;

    for (int i = 1; nb != 0; i *= 10) {
        x += (nb % 8) * i;
        nb /= 8;
    }
    return (x);
}

void my_put_octal(int octal)
{
    my_putchar('\\');
    for (int i = 1; octal * i < 100; i *= 10)
        my_putchar('0');
    my_putnbr(octal);
}

int my_getnbr(char *str)
{
    long result = 0;
    int i = 0;
    int signe = 1;

    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0' && (str[i] == '-' || str[i] == '+'); i++) {
        if (str[i] == '-')
            signe = -1;
    }
    for (;str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            result = (result * 10) + str[i] - 48;
        if (signe == -1 && result > 2147483648)
            return (0);
        if (signe == 1 && result > 2147483647)
            return (0);
    }
    return ((int)result * signe);
}

int calc_nb_nbrs(char *str, int i)
{
    int j = 0;

    for (; check_nbrs(str[i]) == 0; i++, j++);
    return (j);
}
