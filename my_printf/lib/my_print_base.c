/*
** EPITECH PROJECT, 2018
** printyf
** File description:
** print base of numbers
*/

#include "../../include/my_printf.h"

int my_putnbr_base(int nb, char *base)
{
    int result = 0;
    int p = 1;
    int size = my_strlen(base);

    if (nb == -1)
        my_putstr("FFFFFFFF");
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    for (; (nb / p) >= size; p *= size);
    while (p > 0) {
        result = (nb / p) % size;
        my_putchar(base[result]);
        p = p / size;
    }
    return (0);
}

int my_putnbr_base_l(long nbr, char *base)
{
    int i = 0;
    int size = my_strlen(base);
    long nb = 0;

    if (nbr < 0) {
        nbr = -nbr;
        i += 1;
        my_putchar('-');
    }
    if (nbr > 0) {
        nb = nbr;
        nbr /= size;
        i += my_putnbr_base_l(nbr, base);
        i += 1;
        my_putchar(base[nb % size]);
    }
    return (i);
}

void print_hexa(int nb, char *c)
{
    char *base = c;

    my_putnbr_base(nb, base);
}

void my_put_mem(long long nb)
{
    my_putstr("0x");
    my_putnbr_base_l(nb, "0123456789abcdef");
}

int my_putbase_str(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else
            my_put_octal(convert_to_octal((int)str[i]));
    }
    return (0);
}
