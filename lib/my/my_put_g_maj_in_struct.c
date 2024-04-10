/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int my_put_g_maj_in_struct(va_list list)
{
    double value = (double) va_arg(list, double);

    my_put_g(value);
    return 0;
}
