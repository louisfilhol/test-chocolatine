/*
** EPITECH PROJECT, 2023
** day03
** File description:
** put numbr
*/

#include "header.h"
#include <stdarg.h>

int putnbr_else(int nb, int d, int count)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / d) >= 10) {
        d *= 10;
    }
    while (d > 0) {
        my_putchar((nb / d) % 10 + '0');
        d /= 10;
        count++;
    }
    return count;
}

int my_put_nbr(int nb)
{
    int d;
    int count = 0;

    d = 1;
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        count++;
    } else {
        putnbr_else(nb, d, count);
    }
    return count;
}
