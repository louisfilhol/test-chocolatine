/*
** EPITECH PROJECT, 2023
** day14, je sais pas trop
** File description:
** fichier pour tester toutes les fonctions
*/

#include "header.h"

void my_put_nbr_base(unsigned int nb, char *base)
{
    unsigned int div;
    int n_base;

    div = 1;
    n_base = my_strlen(base);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / div) >= n_base)
        div *= n_base;
    while (div > 0) {
        my_putchar(base[(nb / div) % n_base]);
        div /= n_base;
    }
}
