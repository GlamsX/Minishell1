/*
** EPITECH PROJECT, 2018
** new_printf
** File description:
** mod_1
*/

#include "../../include/my_printf.h"

int print_char(va_list ap, int spaces, int *format)
{
    if (format[1] == 2) {
        my_putchar(va_arg(ap, int));
        print_spaces(spaces * -1, 1, format);
        return (0);
    }
    if (spaces > 0)
        for (int i = 0; i != spaces - 1; i++)
            my_putchar(' ');
    my_putchar(va_arg(ap, int));
    return (0);
}

int print_strings(va_list ap, int spaces, int *format)
{
    char *n = va_arg(ap, char *);

    if (format[4] == 1 && spaces < my_strlen(n)) {
        for (int i = 0; i != spaces; i++)
            my_putchar(n[i]);
        return (0);
    }
    if (format[1] == 2 && format[4] == 0) {
        my_putstr(n);
        print_spaces(spaces * -1, my_strlen(n), format);
        return (0);
    }
    if (spaces > my_strlen(n) && format[4] == 0)
        for (int i = 0; i != spaces - my_strlen(n); i++)
            my_putchar(' ');
    my_putstr(n);
    return (0);
}

int print_numbers(va_list ap, int spaces, int *format)
{
    if (format[0] == 0)
        call_simple(ap, spaces, format);
    if (format[0] == 1)
        call_long(ap, spaces, format);
    if (format[0] == 2)
        call_long_long(ap, spaces, format);
    return (0);
}

int print_unsigned(va_list ap, int spaces, int *format)
{
    if (format[0] == 0)
        call_simple_u(ap, spaces, format);
    if (format[0] == 1)
        call_long_u(ap, spaces, format);
    if (format[0] == 2)
        call_long_long_u(ap, spaces, format);
    return (0);
}

int print_pointers(va_list ap, int spaces, int *format)
{
    long nb = va_arg(ap, long);
    char *n = my_getstr_long(nb);
    int size = my_strlen(n);

    if (format[1] == 2) {
        my_put_mem(nb);
        print_spaces(spaces * -1, size + 1, format);
        free(n);
        return (0);
    }
    if (spaces > size)
        for (int i = 0; i != spaces - size - 1; i++)
            my_putchar(' ');
    my_put_mem(nb);
    free(n);
    return (0);
}
