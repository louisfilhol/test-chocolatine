/*
** EPITECH PROJECT, 2023
** fonction putchar
** File description:
** fichier put char A NE PAS PUSH
*/

#include <unistd.h>
#include <stdarg.h>
#include "header.h"

int my_putchar_in_struct(va_list list)
{
    char c = (char) va_arg(list, int);

    my_putchar(c);
    return 0;
}
