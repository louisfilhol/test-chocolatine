/*
** EPITECH PROJECT, 2023
** day03
** File description:
** put numbr
*/

#include "header.h"
#include <stdarg.h>

int my_put_nbr_pos(unsigned int nb)
{
    int d = 1;
    int count = 0;

    while ((nb / d) >= 10) {
        d *= 10;
    }
    while (d > 0) {
        count++;
        my_putchar((nb / d) % 10 + '0');
        d /= 10;
    }
    return count;
}
