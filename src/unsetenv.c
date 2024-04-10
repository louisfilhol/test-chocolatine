/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int unset_env(linked_list_t **env, char *key)
{
    linked_list_t *current = *env;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        if (my_strcmp(current->env->key, key) == 0)
            return remove_env_entry(env, current, prev);
        prev = current;
        current = current->next;
    }
    return 0;
}

int error_setenv_bis(int token_count, char *tokens[], char *cmd_copy)
{
    if (token_count != 2) {
        my_printf("unsetenv: Too few arguments.\n");
        free(cmd_copy);
        return 1;
    }
    if (!is_alphanumeric(tokens[1])) {
        free(cmd_copy);
        return 1;
    }
    return 0;
}

int parse_command_bis(const char *command, char **key)
{
    char *cmd_copy = my_strdup(command);
    char *token;
    int token_count = 0;
    char *tokens[4] = {0};

    token = strtok(cmd_copy, " ");
    while (token != NULL && token_count < 4) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " ");
    }
    if (error_setenv_bis(token_count, tokens, cmd_copy) == 1)
        return 1;
    *key = my_strdup(tokens[1]);
    free(cmd_copy);
    return 0;
}

int unset_env_check(linked_list_t *env, char *user_command)
{
    char *key;

    if (my_strncmp(user_command, "unsetenv ", 8) == 0) {
        if (parse_command_bis(user_command, &key) == 0)
            unset_env(&env, key);
        else
            return 0;
        return 0;
    }
    return 1;
}
