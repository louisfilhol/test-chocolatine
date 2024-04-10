/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int cd_error(char *path, int number)
{
    int strlen_path = my_strlen(path);

    if (number == 0) {
        write(2, path, strlen_path + 1);
        write(2, ": Not a directory.\n", 20);
    }
    if (number == 2) {
        write(2, path, strlen_path);
        write(2, ": No such file or directory.\n", 29);
    }
    if (number == 3) {
        write(2, "cd: Too many arguments.\n", 24);
    }
    return 0;
}

void free_stuff(char *cmd_copy, char **param_list)
{
    free(cmd_copy);
    free(param_list);
}

int fix_issue(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;
    }
    return 1;
}

int execve_error(char *command, minishell_t *minishell)
{
    struct stat path_stat;

    if (my_strncmp(command, "./", 2) == 0) {
        if (stat(command, &path_stat) == -1) {
            my_printf("%s: Command not found.\n", command);
            return 0;
        }
        if (S_ISDIR(path_stat.st_mode)) {
            my_printf("%s: Permission denied.\n", command);
            return 1;
        }
        if (!S_ISREG(path_stat.st_mode) || !(path_stat.st_mode & S_IXUSR)) {
            my_printf("%s: Command not found or not executable.\n", command);
            return 1;
        }
    }
    return 0;
}

int is_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') && str[i] != '_') {
            return 0;
        }
    }
    my_printf("setenv: Variable name must contain alphanumeric characters.\n");
    return 1;
}
