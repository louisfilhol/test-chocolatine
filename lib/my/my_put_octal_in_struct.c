/*
** EPITECH PROJECT, 2023
** navy
** File description:
** struct
*/

#include "header.h"
#include <stdio.h>
#include <stdarg.h>

int my_put_octal_in_struct(va_list list)
{
    unsigned int value = (unsigned int) va_arg(list, unsigned int);

    my_put_octal(value);
    return 0;
}
