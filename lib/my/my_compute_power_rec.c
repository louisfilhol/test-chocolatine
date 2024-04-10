/*
** EPITECH PROJECT, 2023
** Day05, Task04
** File description:
** fonction qui renvoie lr 1er argumrent monté a la puissance du 2e argument
*/

int my_compute_power_rec(int nb, int p)
{
    if ((p < 0) | (nb > 12)) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}
