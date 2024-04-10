/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_getnbr
*/

int is_still_nbr(int index, char const *str, int nbr)
{
    for (int k = index; str[k] != '\0'; k++) {
        if (str[k] >= '0' && str[k] <= '9')
            nbr = nbr * 10 + (str[k] - '0');
        else
            return nbr;
    }
    return nbr;
}

int my_getnbr(char const *str)
{
    int pos = 1;
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            pos = pos * -1;
    }
    for (int k = 0; str[k] != '\0'; k++) {
        if (str[k] >= '0' && str[k] <= '9') {
            nbr = is_still_nbr(k, str, nbr);
            return nbr;
        }
    }
    nbr = nbr * pos;
    return nbr;
}
