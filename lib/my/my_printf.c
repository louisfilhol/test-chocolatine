/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "header.h"


point_t point_s_array[] = {
    {"c", my_putchar_in_struct},
    {"s", my_putstr_in_struct},
    {"d", my_put_nbr_in_struct},
    {"i", my_put_nbr_in_struct},
    {"f", my_put_float_in_struct},
    {"F", my_put_float_in_struct},
    {"e", my_put_scientific_in_struct},
    {"E", my_put_scientific_maj_in_struct},
    {"g", my_put_g_in_struct},
    {"G", my_put_g_maj_in_struct},
    {"X", my_put_hexadecimal_maj_in_struct},
    {"o", my_put_octal_in_struct},
    {"u", my_put_nbr_pos_in_struct},
    {"p", my_put_adress_in_struct},
    {"lf", my_put_float_in_struct},
    {"Lf", my_put_float_in_struct},
    {"%", print_percent_in_struct},
    {0, NULL}
};

void my_size(int size, int *i)
{
    if (size > 1)
        (*i) += size - 1;
}

void handle_format(va_list list, char *rest_format, int *i)
{
    int size = 0;

    for (int j = 0; point_s_array[j].ptr != NULL; j++) {
        size = my_strlen(point_s_array[j].a);
        if (my_strncmp(point_s_array[j].a, rest_format, size) == 0) {
            point_s_array[j].ptr(list);
            my_size(size, i);
            break;
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            handle_format(list, (char *)(format + i), &i);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return 0;
}
