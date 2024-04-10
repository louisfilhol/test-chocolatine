/*
** EPITECH PROJECT, 2023
** Day04, Task01
** File description:
** swap le contenu de deux variables int
*/

void my_swap(int *nb1, int *nb2)
{
    int x = *nb1;

    *nb1 = *nb2;
    *nb2 = x;
}
