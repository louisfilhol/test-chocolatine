/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int exit_command(char *command, linked_list_t *env, minishell_t *minishell)
{
    free(command);
    free_linked_list(env);
    free(minishell);
    exit(0);
    return 0;
}

int show_env(linked_list_t *env)
{
    linked_list_t *temp = env;

    while (temp != NULL) {
        my_printf("%s=%s\n", temp->env->key, temp->env->value);
        temp = temp->next;
    }
    return 0;
}

char *make_sure(char *path)
{
    char *string;

    if (my_strcmp(path, "bin/ls") == 0)
        string = "/bin/ls";
    else
        return path;
    return string;
}

int cd_dir(char *path)
{
    struct stat path_stat;
    char *string = make_sure(path);

    if (count_words(path) > 1) {
        cd_error(path, 3);
        return 1;
    }
    if (stat(string, &path_stat) == -1) {
        cd_error(path, 2);
        return 1;
    }
    if (S_ISREG(path_stat.st_mode)) {
        cd_error(path, 0);
        return 1;
    }
    if (chdir(path) != 0) {
        return 1;
    }
    return 0;
}

int cd_root(linked_list_t *env)
{
    char *home;

    while (env != NULL) {
        if (my_strcmp(env->env->key, "HOME") == 0)
            home = env->env->value;
        env = env->next;
    }
    cd_dir(home);
    return 0;
}
