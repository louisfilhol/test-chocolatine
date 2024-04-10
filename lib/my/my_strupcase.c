/*
** EPITECH PROJECT, 2023
** day07
** File description:
** strupcase
*/

#include <unistd.h>
#include "header.h"

char *my_strupcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
