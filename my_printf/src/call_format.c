/*
** EPITECH PROJECT, 2018
** new_printf
** File description:
** call_format
*/

#include "../../include/my_printf.h"

void formating(int spaces, int size, int *format)
{
    if (format[3] == 0) {
        print_spaces_or_zero(spaces, size + 1, format);
        my_putchar('+');
    }
    if (format[3] == 1) {
        my_putchar('+');
        print_spaces_or_zero(spaces, size + 1, format);
    }
}

void call_simple(va_list ap, int spaces, int *format)
{
    int nb = va_arg(ap, int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_putnbr(nb);
    }
    if (format[1] == 1) {
        formating(spaces, size, format);
        my_putnbr(nb);
    }
    if (format[1] == 2) {
        my_putnbr(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}

void call_long(va_list ap, int spaces, int *format)
{
    long nb = va_arg(ap, long int);
    char *n = my_getstr_long(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_put_l(nb);
    }
    if (format[1] == 1) {
        formating(spaces, size, format);
        my_put_l(nb);
    }
    if (format[1] == 2) {
        my_put_l(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}

void call_long_long(va_list ap, int spaces, int *format)
{
    long long nb = va_arg(ap, long long int);
    char *n = my_getstr_long_long(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_put_ll(nb);
    }
    if (format[1] == 1) {
        formating(spaces, size, format);
        my_put_ll(nb);
    }
    if (format[1] == 2) {
        my_put_ll(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}
