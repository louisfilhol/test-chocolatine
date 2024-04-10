/*
** EPITECH PROJECT, 2023
** navy
** File description:
** struct
*/

#include "header.h"
#include <stdio.h>
#include <stdarg.h>

int my_put_octal(unsigned int value)
{
    char octal[32];
    int i = 0;
    int count = 0;

    if (value == 0) {
        my_putchar('0');
        count++;
        return count;
    }
    while (value > 0) {
        octal[i] = (value % 8) + '0';
        value = value / 8;
        i++;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_putchar(octal[k]);
        count++;
    }
    return count;
}
