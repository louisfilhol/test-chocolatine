/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int print_percent_in_struct(va_list list)
{
    (void)list;
    my_putchar('%');
    return 0;
}
