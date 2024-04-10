/*
** EPITECH PROJECT, 2023
** Day04, Task02
** File description:
** display une chaine de caractères, avec des pointers
*/

#include "header.h"
#include <stdarg.h>

int my_putstr_in_struct(va_list list)
{
    char const *str = (char const *) va_arg(list, char *);

    my_putstr(str);
    return 0;
}
