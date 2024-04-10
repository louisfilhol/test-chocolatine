/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int count_tokens(const char *str, char delim)
{
    int count = 1;

    while (*str) {
        if (*str == delim)
            count++;
        str++;
    }
    return count;
}

char *setup_path(linked_list_t *env, minishell_t *minishell)
{
    linked_list_t *temp_env = env;
    char *path;

    while (temp_env != NULL) {
        if (my_strcmp(temp_env->env->key, "PATH") == 0)
            path = temp_env->env->value;
        temp_env = temp_env->next;
    }
    return path;
}

void *setup_minishell(minishell_t *minishell, linked_list_t *env,
    char *path)
{
    char *temp_path = my_strdup(path);
    char *token;
    int path_number = count_tokens(path, ':');
    int i = -1;

    minishell->path = malloc(path_number * sizeof(char *));
    token = strtok(temp_path, ":");
    while (token != NULL) {
        i++;
        minishell->path[i] = my_strdup(token);
        token = strtok(NULL, ":");
    }
    minishell->path[i] = NULL;
    minishell->number_path = path_number;
}
