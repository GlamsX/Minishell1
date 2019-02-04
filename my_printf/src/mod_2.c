/*
** EPITECH PROJECT, 2018
** new_printf
** File description:
** mod_2
*/

#include "../../include/my_printf.h"

int print_special_str(va_list ap, int spaces, int *format)
{
    char *n = va_arg(ap, char *);
    int size = my_strlen(n);

    if (format[1] == 2) {
        my_putbase_str(n);
        print_spaces(spaces * -1, size, format);
        return (0);
    }
    if (spaces > size)
        for (int i = 0; i < spaces - size; i++)
            my_putchar(' ');
    my_putbase_str(n);
    return (0);
}

int print_octal(va_list ap, int spaces, int *format)
{
    int nb = va_arg(ap, int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 2) {
        if (format[2] == 1)
            my_putchar('0');
        my_putnbr(convert_to_octal(nb));
        print_spaces(spaces * -1, size, format);
        free(n);
        return (0);
    }
    print_spaces_or_zero(spaces, size, format);
    my_putnbr(convert_to_octal(nb));
    free(n);
    return (0);
}

int print_decimal(va_list ap, int spaces, int *format)
{
    int nb = va_arg(ap, int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 2) {
        my_putnbr_base(nb, "01");
        print_spaces(spaces * -1, size, format);
        free(n);
        return (0);
    }
    if (spaces > size)
        for (int i = 0; i != spaces - size; i++)
            my_putchar(' ');
    my_putnbr_base(nb, "01");
    free(n);
    return (0);
}

int print_hexadcimal(va_list ap, int spaces, int *format)
{
    int nb = va_arg(ap, int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 2) {
        if (format[2] == 1)
            my_putstr("0x");
        print_hexa(nb, "0123456789abcdef");
        print_spaces(spaces * -1, size - 1, format);
        free(n);
        return (0);
    }
    speciale_print_exa(spaces, size - 1, format);
    print_hexa(nb, "0123456789abcdef");
    free(n);
    return (0);
}

int print_hexa_maj(va_list ap, int spaces, int *format)
{
    int nb = va_arg(ap, int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 2) {
        if (format[2] == 1)
            my_putstr("0X");
        print_hexa(nb, "0123456789ABCDEF");
        print_spaces(spaces * -1, size - 1, format);
        free(n);
        return (0);
    }
    speciale_print_exa_maj(spaces, size - 1, format);
    print_hexa(nb, "0123456789ABCDEF");
    free(n);
    return (0);
}
