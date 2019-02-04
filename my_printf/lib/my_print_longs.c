/*
** EPITECH PROJECT, 2018
** prihntf
** File description:
** print long numbers and long long and unsigned
*/

#include "../../include/my_printf.h"

void my_put_l(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0) {
        my_putchar('0');
        return;
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return;
    } else
        my_putchar('0' + nb);
}

void my_put_ul(unsigned long int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return;
    } else
        my_putchar('0' + nb);
}

void my_put_ll(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0) {
        my_putchar('0');
        return;
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return;
    } else
        my_putchar('0' + nb);
}

void my_put_ull(unsigned long long int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return;
    } else
        my_putchar('0' + nb);

}

void my_put_u(unsigned nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    } else if (nb > 9) {
        my_putnbr((nb - (nb % 10)) / 10);
        my_putchar('0' + (nb % 10));
        return;
    } else
        my_putchar('0' + nb);

}
