/*
** EPITECH PROJECT, 2023
** mylib
** File description:
** library
*/

#pragma once
#include <stdarg.h>

typedef struct point_s_array {
    char *a;
    int (*ptr)(va_list);
} point_t;

int my_printf(const char *format, ...);
int print_percent(void);
int my_putchar_in_struct(va_list list);
int my_putchar(char c);
int my_isneg(int nb);
int my_put_g(double value);
int my_put_scientific(double mantissa);
int my_put_nbr(int nb);
int my_put_nbr_pos(unsigned int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_adress(const void *ptr);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_put_hexadecimal_bis(unsigned int value, char *hexa, int i);
int my_put_octal(unsigned int value);
int my_put_scientific_maj(double nbr);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_put_float(double number);
int my_put_adress(const void *ptr);
int my_put_float_in_struct(va_list list);
int my_putstr_in_struct(va_list list);
int my_put_scientific_in_struct(va_list list);
int my_put_scientific_maj_in_struct(va_list list);
int my_put_octal_in_struct(va_list list);
int my_put_hexadecimal_maj_in_struct(va_list list);
int my_put_nbr_in_struct(va_list list);
int my_put_adress_in_struct(va_list list);
int my_put_nbr_pos_in_struct(va_list list);
int my_put_g_in_struct(va_list list);
int my_put_g_maj_in_struct(va_list list);
int print_percent_in_struct(va_list list);
int my_ls(int argc, char **argv);
char *my_strdup(const char *s);
char *my_strndup(const char *s, int n);
