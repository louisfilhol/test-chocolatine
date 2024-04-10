/*
** EPITECH PROJECT, 2023
** Project Name
** File description:
** Project Description
*/

#include "../includes/minishell1.h"

int set_env_bis(linked_list_t *tmp, linked_list_t *new_node, char *key,
    char *value
)
{
    while (tmp->next != NULL) {
        if (my_strcmp(tmp->env->key, key) == 0) {
            free(tmp->env->value);
            tmp->env->value = my_strdup(value);
            return 0;
        }
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return 0;
}

int set_env(linked_list_t **env, char *key, char *value)
{
    env_t *new_env = malloc(sizeof(env_t));
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = *env;

    new_env->key = my_strdup(key);
    new_env->value = my_strdup(value);
    new_node->env = new_env;
    new_node->next = NULL;
    if (*env == NULL)
        *env = new_node;
    else
        set_env_bis(tmp, new_node, key, value);
    return 0;
}

int error_setenv(int token_count, char *tokens[], char *cmd_copy)
{
    if (token_count > 3) {
        my_printf("setenv: Too many arguments.\n");
        free(cmd_copy);
        return 1;
    }
    if (token_count < 2) {
        free(cmd_copy);
        return 1;
    }
    if (token_count == 2)
        tokens[2] = "";
    if (is_alphanumeric(tokens[1]) == 1) {
        free(cmd_copy);
        return 1;
    }
    return 0;
}

int parse_command(const char *command, char **key, char **value)
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
    if (error_setenv(token_count, tokens, cmd_copy) == 1)
        return 1;
    *key = my_strdup(tokens[1]);
    *value = my_strdup(tokens[2]);
    free(cmd_copy);
    return 0;
}

int setenv_check(linked_list_t *env, char *user_command)
{
    char *key;
    char *value;

    if (my_strncmp(user_command, "setenv ", 6) == 0) {
        if (parse_command(user_command, &key, &value) == 0)
            set_env(&env, key, value);
        else
            return 0;
        return 0;
    }
    return 1;
}
