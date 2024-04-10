/*
** EPITECH PROJECT, 2023
** day07
** File description:
** str cat ptdr c'est quoi ca encore
*/

#include "header.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
