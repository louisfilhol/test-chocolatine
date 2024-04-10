/*
** EPITECH PROJECT, 2023
** my_put_hexadecimal
** File description:
** print an hexadecimal value from an int
*/

#include "header.h"
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

int my_put_adress_in_struct(va_list list)
{
    const void *ptr = (const void *) va_arg(list, const void *);

    my_put_adress(ptr);
    return 0;
}
