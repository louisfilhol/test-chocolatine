/*
** EPITECH PROJECT, 2023
** my_put_hexadecimal
** File description:
** print an hexadecimal value from an int
*/

#include "header.h"
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

int my_put_adress(const void *ptr)
{
    uintptr_t adress = (uintptr_t)ptr;
    char hexa[16];
    int i = 0;
    int temp = 0;
    int count;

    while (adress > 0) {
        temp = (adress % 16);
        if (temp < 10)
            hexa[i] = temp + '0';
        else
            hexa[i] = temp - 10 + 'a';
        adress /= 16;
        i++;
    }
    my_putstr("0x");
    count = i + 1;
    for (int k = i - 1; k >= 0; k--)
        my_putchar(hexa[k]);
    return count;
}
