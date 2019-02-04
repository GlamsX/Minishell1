/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#ifndef MY_PRINTF_
#define MY_PRINTF_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct flags_s
{
    char flag;
    int (*name)(va_list, int, int *);
} flags_t;

void print_spaces(int, int, int *);
char *nb_space(char *, int);
void call_simple_u(va_list, int, int *);
void call_long_u(va_list, int, int *);
void call_long_long_u(va_list, int, int *);
void call_simple(va_list, int, int *);
void call_long(va_list, int, int *);
void call_long_long(va_list, int, int *);
int print_char(va_list, int, int *);
int print_special_str(va_list, int, int *);
int print_octal(va_list, int, int *);
int print_hexa_maj(va_list, int, int *);
int print_decimal(va_list, int, int *);
int print_hexadcimal(va_list, int, int *);
int print_unsigned(va_list, int, int *);
int print_pointers(va_list, int, int *);
int print_strings(va_list, int,  int *);
int print_numbers(va_list, int, int *);
int convert_to_octal(int);
void my_put_octal(int);
int my_putbase_str(char *);
void my_put_address(long long);
void print_hexa(int, char *);
int my_putnbr_base_l(long, char *);
int my_putnbr_base(int, char *);
void my_put_u(unsigned);
void my_put_ull(unsigned long long int);
void my_put_ll(long long int);
void my_put_l(long int);
void my_putnbr_float(double);
void float_print(long);
void my_putstr(char *);
void my_putchar(char c);
int check_nbrs(char);
void my_put_ul(unsigned long int);
int check_flags(char);
int check_format(char);
int check_doublons(char);
char *my_getstr(int);
char *my_getstr_long(long);
char *my_getstr_long_long(long long);
void my_put_mem(long long);
void print_spaces_or_zero(int, int, int *);
int calc_nb_nbrs(char *, int);
void formating(int, int, int *);
void speciale_print_exa(int, int, int *);
void speciale_print_exa_maj(int, int, int *);
int my_getnbr(char *);
int my_strlen(char *);
int my_putnbr(int);
void my_printf(char *, ...);

#endif
