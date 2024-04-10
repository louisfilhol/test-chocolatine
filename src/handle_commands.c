/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int handle_commands_bis(char *command, linked_list_t *env,
    minishell_t *minishell)
{
    int return_number;

    if (my_strncmp(command, "cd ", 3) == 0) {
        return_number = cd_dir(command + 3);
        minishell->return_number = return_number;
        return 0;
    }
    if (my_strcmp(command, "echo $?") == 0) {
        my_printf("%d\n", minishell->return_number);
        minishell->return_number = 0;
        return 0;
    }
    return 1;
}

int handle_commands(char *command, linked_list_t *env, minishell_t *minishell)
{
    int return_number;

    if (my_strcmp(command, "exit") == 0)
        exit_command(command, env, minishell);
    if (my_strcmp(command, "env") == 0) {
        show_env(env);
        minishell->return_number = 0;
        return 0;
    }
    if (my_strcmp(command, "cd") == 0) {
        cd_root(env);
        minishell->return_number = 0;
        return 0;
    }
    if (handle_commands_bis(command, env, minishell) == 0)
        return 0;
    return 1;
}
