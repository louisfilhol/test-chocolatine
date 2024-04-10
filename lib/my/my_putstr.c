/*
** EPITECH PROJECT, 2023
** Day04, Task02
** File description:
** display une chaine de caractères, avec des pointers
*/

#include "header.h"
#include <stdarg.h>

int my_putstr(char const *str)
{
    int count = 0;

    while (*str != '\0') {
        my_putchar(*str);
        str++;
        count++;
    }
    return count;
}
