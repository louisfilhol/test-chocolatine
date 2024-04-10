/*
** EPITECH PROJECT, 2023
** Day06, Task01
** File description:
** function that copies a string onto another string
*/

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strdup(const char *s)
{
    int size = my_strlen(s) + 1;
    char *new_str = (char *)malloc(size);

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < size; ++i)
        new_str[i] = s[i];
    return new_str;
}
