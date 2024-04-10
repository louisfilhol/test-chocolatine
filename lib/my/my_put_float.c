/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int my_put_float(double number)
{
    long integerPart;
    long decimalPart;
    double decimalFraction;

    integerPart = number;
    decimalPart = number * (float)1000000;
    decimalPart -= integerPart * 1000000;
    decimalFraction = (double)decimalPart;
    my_put_nbr(integerPart);
    my_putchar('.');
    my_put_nbr((long)decimalFraction);
    return 0;
}
