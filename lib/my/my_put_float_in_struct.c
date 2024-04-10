/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int my_put_float_in_struct(va_list list)
{
    double number = (double) va_arg(list, double);

    my_put_float(number);
    return 0;
}
