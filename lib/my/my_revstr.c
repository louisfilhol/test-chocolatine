/*
** EPITECH PROJECT, 2023
** Day06, Task03
** File description:
** function that reverses a str
*/

int lengh(char const *str)
{
    int x = 0;

    while (*str != '\0') {
        str++;
        x++;
    }
    return x;
}

void swap_char(char *a, char *b)
{
    char temp_place = *a;

    *a = *b;
    *b = temp_place;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = lengh(str);

    for (i = 0; i < len / 2; i++) {
        swap_char(&str[i], &str[len - i - 1]);
    }
    return str;
}
