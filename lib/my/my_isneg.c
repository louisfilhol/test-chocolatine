/*
** EPITECH PROJECT, 2023
** task04
** File description:
** vérifier si le nombre est négatif, positif ou nul
*/

#include "header.h"

int my_isneg(int c)
{
    if (c < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
