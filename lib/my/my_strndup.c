/*
** EPITECH PROJECT, 2023
** Day06, Task01
** File description:
** function that copies a string onto another string
*/

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strndup(const char *s, int n)
{
    int size = my_strlen(s);
    char *new_str = (char *)malloc(size + 1);

    if (size > n)
        size = n;
    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < size; ++i)
        new_str[i] = s[i];
    new_str[size] = '\0';
    return new_str;
}
