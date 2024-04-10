/*
** EPITECH PROJECT, 2023
** Day06, Task01
** File description:
** function that copies a string onto another string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
