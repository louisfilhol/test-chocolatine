/*
** EPITECH PROJECT, 2023
** day03
** File description:
** put numbr
*/

#include "header.h"
#include <stdarg.h>

int my_put_nbr_in_struct(va_list list)
{
    int nb = (int) va_arg(list, int);

    my_put_nbr(nb);
    return 0;
}
