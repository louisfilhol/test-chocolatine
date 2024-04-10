/*
** EPITECH PROJECT, 2023
** day03
** File description:
** put numbr
*/

#include "header.h"
#include <stdarg.h>

int my_put_nbr_pos_in_struct(va_list list)
{
    unsigned int nb = (unsigned int) va_arg(list, unsigned int);

    my_put_nbr_pos(nb);
    return 0;
}
