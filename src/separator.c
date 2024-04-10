/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int separator_command(char *command, linked_list_t *env,
    minishell_t *minishell)
{
    if (command[0] == 'c' && command[1] == 'd') {
        if (launcher(command, env, minishell) == 0)
            return 0;
    } else {
        execute_command(command, env, minishell);
    }
}

char **split_commands(char *command, int *num_commands, int semicolon_nbr)
{
    int max_commands = semicolon_nbr + 1;
    char **commands = malloc(max_commands * sizeof(char *));
    char *token;

    for (int i = 0; i < max_commands; i++)
        commands[i] = malloc((my_strlen(command) + 1) * sizeof(char));
    *num_commands = 0;
    token = strtok(command, ";");
    while (token != NULL && *num_commands < max_commands) {
        while (*token == ' ')
            token++;
        my_strncpy(commands[*num_commands], token, my_strlen(token) + 1);
        (*num_commands)++;
        token = strtok(NULL, ";");
    }
    return commands;
}

int handle_seperator(char *command, linked_list_t *env, minishell_t *minishell)
{
    int semicolon_nbr = 0;
    int num_commands = 0;
    char **commands;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == ';') {
            semicolon_nbr++;
        }
    }
    if (semicolon_nbr == 0) {
        separator_command(command, env, minishell);
        return 0;
    }
    commands = split_commands(command, &num_commands, semicolon_nbr);
    for (int i = 0; i < num_commands; i++)
        separator_command(commands[i], env, minishell);
    for (int i = 0; i < num_commands; i++)
        free(commands[i]);
    free(commands);
    return 0;
}

int launcher_pipe(char *first, char *second, minishell_t *minishell)
{
    char *cmd1[] = { first, NULL };
    char *cmd2[] = { second, NULL };

    run_pipe_command(cmd1, cmd2, minishell);
}
