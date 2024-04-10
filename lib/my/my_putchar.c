/*
** EPITECH PROJECT, 2023
** fonction putchar
** File description:
** fichier put char A NE PAS PUSH
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
