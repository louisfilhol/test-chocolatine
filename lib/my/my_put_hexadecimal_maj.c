/*
** EPITECH PROJECT, 2023
** my_put_hexadecimal
** File description:
** print an hexadecimal value from an int
*/

#include "header.h"
#include <stdio.h>
#include <stdarg.h>


int my_put_hexadecimal2(unsigned int value, char *hexa, int i)
{
    int count = 0;
    int temp = 0;

    while (value > 0) {
        temp = (value % 16);
        if (temp < 10)
            hexa[i] = temp + '0';
        else
            hexa[i] = temp - 10 + 'A';
        value = value / 16;
        i++;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_putchar(hexa[k]);
        count++;
    }
    return count;
}

int my_put_hexadecimal_maj(unsigned int value)
{
    char hexa[64];
    int i = 0;
    int count = 0;

    if (value == 0) {
        my_putchar('0');
        count++;
        return count;
    }
    count = my_put_hexadecimal2(value, hexa, i);
    return count;
}

int my_put_hexadecimal_maj_in_struct(va_list list)
{
    unsigned int value = (unsigned int) va_arg(list, unsigned int);

    my_put_hexadecimal_maj(value);
    return 0;
}
