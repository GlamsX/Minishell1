/*
** EPITECH PROJECT, 2018
** privntf
** File description:
** print basics
*/

#include "../../include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return (0);
    } else
        my_putchar('0' + nb);
    return (0);
}

void float_print(long y)
{
    for (int i = 0; i != 6; i++)
        my_putchar((y % 10) + 48);
}

void my_putnbr_float(double nb)
{
    double y = (nb - (nb - 1)) * 100000;
    long j = nb;

    my_putnbr_base_l(j, "0123456789");
    my_putchar('.');
    float_print((long)y);
}
