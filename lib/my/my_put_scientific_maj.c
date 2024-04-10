/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int display_result(int exponent, double mantissa)
{
    my_put_float(mantissa);
    my_putchar('E');
    if (exponent < 0) {
        exponent *= - 1;
        my_putchar('-');
    } else {
        my_putchar('+');
    }
    if (exponent < 10)
        my_putchar('0');
    my_put_nbr(exponent);
    return 0;
}

int my_put_scientific_maj(double nbr)
{
    int exponent = 0;
    double mantissa = nbr;

    if (mantissa < 0) {
        mantissa *= - 1;
        my_putchar('-');
    }
    while (mantissa >= 10) {
        mantissa /= 10;
        exponent++;
    }
    while (mantissa < 1) {
        mantissa *= 10;
        exponent--;
    }
    display_result(exponent, mantissa);
    return 0;
}
