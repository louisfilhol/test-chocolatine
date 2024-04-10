/*
** EPITECH PROJECT, 2023
** Day04, Task03
** File description:
** compter le nombre de caractères dans un str de characters
*/

int my_strlen(char const *str)
{
    int x = 0;

    while (*str != '\0') {
        str++;
        x++;
    }
    return x;
}
