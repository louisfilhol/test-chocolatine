/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

const char *loc_equals(const char *str)
{
    for (; *str != '\0'; ++str) {
        if (*str == '=')
            return str;
    }
    return NULL;
}

env_t *select_line(const char *env_str)
{
    env_t *env = (env_t *)malloc(sizeof(env_t));
    const char *equal_pos;
    int length_key;

    equal_pos = loc_equals(env_str);
    if (equal_pos != NULL) {
        length_key = equal_pos - env_str;
        env->key = my_strndup(env_str, length_key);
        env->value = my_strdup(equal_pos + 1);
    } else {
        env->key = my_strdup(env_str);
        env->value = my_strdup("");
    }
    return env;
}

linked_list_t *initialize_env(char **env)
{
    linked_list_t *list_head = NULL;
    linked_list_t *list_tail = NULL;
    linked_list_t *current_node = NULL;

    for (int i = 0; env[i] != NULL; ++i) {
        current_node = (linked_list_t *)malloc(sizeof(linked_list_t));
        if (current_node == NULL) {
            return NULL;
        }
        current_node->env = select_line(env[i]);
        current_node->next = NULL;
        if (list_head == NULL) {
            list_head = current_node;
            list_tail = current_node;
        } else {
            list_tail->next = current_node;
            list_tail = current_node;
        }
    }
    return list_head;
}

int remove_env_entry(linked_list_t **env, linked_list_t *current,
    linked_list_t *prev)
{
    if (prev == NULL)
        *env = current->next;
    else
        prev->next = current->next;
    free(current->env->key);
    free(current->env->value);
    free(current->env);
    free(current);
    return 0;
}

int path_issues(linked_list_t *env)
{
    linked_list_t *current = env;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        if (my_strcmp(current->env->key, "PWD") == 0)
            my_printf("%s\n", current->env->value);
        prev = current;
        current = current->next;
    }
    return 0;
}
