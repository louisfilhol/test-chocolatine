/*
** EPITECH PROJECT, 2023
** Day05, Task05
** File description:
** trouver la racine carrée d'un nombre
*/

int my_compute_square_root(int nb)
{
    int square_root = nb / 2;

    if (nb < 0) {
        return 0;
    }
    while (square_root * square_root != nb) {
        if (square_root == 0)
        square_root--;
        if (square_root * square_root == nb) {
            return square_root;
        }
    }
    return 0;
}
