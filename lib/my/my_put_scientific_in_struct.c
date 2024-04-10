/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int my_put_scientific_in_struct(va_list list)
{
    double nbr = (double) va_arg(list, double);

    my_put_scientific(nbr);
    return 0;
}
