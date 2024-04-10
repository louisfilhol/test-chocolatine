/*
** EPITECH PROJECT, 2023
** day07
** File description:
** strlowcase
*/

#include <unistd.h>
#include "header.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
