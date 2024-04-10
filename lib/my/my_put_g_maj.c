/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** project
*/

#include "header.h"
#include <stdarg.h>

int my_put_g_maj(double value)
{
    if (value >= 0.0001 && value <= 10000) {
        my_put_float(value);
    } else {
        my_put_scientific_maj(value);
    }
    return 0;
}
