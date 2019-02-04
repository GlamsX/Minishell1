/*
** EPITECH PROJECT, 2018
** new_printf
** File description:
** my_printf
*/

#include "../../include/my_printf.h"

static const flags_t flags_g[] = {
    {'c', &print_char},
    {'s', &print_strings},
    {'i', &print_numbers},
    {'d', &print_numbers},
    {'u', &print_unsigned},
    {'p', &print_pointers},
    {'S', &print_special_str},
    {'o', &print_octal},
    {'b', &print_decimal},
    {'x', &print_hexadcimal},
    {'X', &print_hexa_maj},
    {0, NULL}
};

int brows_flags(va_list ap, int nb_spaces, int *format, char flag)
{
    for (int i = 0; flags_g[i].flag != 0; i++) {
        if (flags_g[i].flag == flag) {
            flags_g[i].name(ap, nb_spaces, format);
            return (0);
        }
    }
    return (1);
}

void norming_1(char str, int *format, int *nff)
{
    if (check_format(str) == 0)
        format[0]++;
    if (str == '#')
        format[2] = 1;
    if (str == '.')
        format[4] = 1;
    if (str == '+')
        format[1] = 1;
    if (str == '-')
        format[1] = 2;
    if (check_flags(str) != 0 && check_nbrs(str) != 0
        && check_format(str) != 0)
        (*nff)++;
}

int norming_2(char *nb_space, int *i, int *nff)
{
    if ((*nff) > 1) {
        free(nb_space);
        my_putchar('%');
        return ((*i) - 1);
    }
    my_putchar('%');
    free(nb_space);
    return ((*i) - 1);
}

int call_flag(char *str, va_list ap, int i)
{
    int j = i;
    char *nb_spac = nb_space(str, i);
    int nb_sp = my_getnbr(nb_spac);
    int format[5] = {0, 0, 0, 0, 0};
    int no_flag_format = 0;
    char flag;

    if (str[j] == '0' || str[j + 1] == '0')
        format[3] = 1;
    for (; check_flags(str[j]) != 0; j++)
        norming_1(str[j], format, &no_flag_format);
    flag = str[j];
    if (no_flag_format < 2) {
        if (brows_flags(ap, nb_sp, format, flag) == 0) {
            free(nb_spac);
            return (j);
        }
    }
    return (norming_2(nb_spac, &i, &no_flag_format));
}

void my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            if (str[i] == '%')
                my_putchar('%');
            else
                i = call_flag(str, ap, i);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
}
