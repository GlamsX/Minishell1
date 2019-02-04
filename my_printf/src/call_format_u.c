/*
** EPITECH PROJECT, 2018
** new_printf
** File description:
** callc_unsigned format
*/

#include "../../include/my_printf.h"

void call_simple_u(va_list ap, int spaces, int *format)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *n = my_getstr(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_put_u(nb);
    }
    if (format[1] == 1) {
        print_spaces_or_zero(spaces, size, format);
        my_put_u(nb);
    }
    if (format[1] == 2) {
        my_put_u(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}

void call_long_u(va_list ap, int spaces, int *format)
{
    unsigned long nb = va_arg(ap, unsigned long int);
    char *n = my_getstr_long(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_put_ul(nb);
    }
    if (format[1] == 1) {
        print_spaces_or_zero(spaces, size, format);
        my_put_ul(nb);
    }
    if (format[1] == 2) {
        my_put_ul(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}

void call_long_long_u(va_list ap, int spaces, int *format)
{
    unsigned long long nb = va_arg(ap, unsigned long long int);
    char *n = my_getstr_long_long(nb);
    int size = my_strlen(n);

    if (format[1] == 0) {
        print_spaces_or_zero(spaces, size, format);
        my_put_ull(nb);
    }
    if (format[1] == 1) {
        print_spaces_or_zero(spaces, size, format);
        my_put_ull(nb);
    }
    if (format[1] == 2) {
        my_put_ull(nb);
        print_spaces(spaces * -1, size, format);
    }
    free(n);
}
