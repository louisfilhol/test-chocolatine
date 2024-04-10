/*
** EPITECH PROJECT, 2023
** day07
** File description:
** str cat ptdr c'est quoi ca encore
*/

#include "header.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
