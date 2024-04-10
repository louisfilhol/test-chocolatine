/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int run(char *path_to_exec, char **param_list, minishell_t *minishell)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0)
        return exec_child(path_to_exec, param_list);
    else if (child_pid > 0) {
        waitpid(child_pid, &status, 0);
        return handle_status(status, minishell);
    }
    return -1;
}

char *seperate_command(char *command, char **param_list)
{
    char *temp_command = my_strdup(command);
    int j = 0;
    char *token = strtok(temp_command, " ");

    while (token != NULL) {
        param_list[j] = token;
        j++;
        token = strtok(NULL, " ");
    }
    param_list[j] = NULL;
    return temp_command;
}

int find_and_run_command(char *command, char **paths, minishell_t *minishell)
{
    char *param_list[64];
    char *temp_command = seperate_command(command, param_list);
    int return_number;

    if (command[0] == '/' || my_strncmp(command, "./", 2) == 0) {
        return_number = try_run_direct_command(command, param_list, minishell);
        if (return_number != -1) {
            free(temp_command);
            return return_number;
        }
    }
    return_number = try_run_command_from_paths(paths,
        param_list, temp_command, minishell);
    if (return_number != -1) {
        free(temp_command);
        return return_number;
    }
    my_printf("%s: Command not found.\n", command);
    free(temp_command);
    return 1;
}

int execve_binary(char *command, minishell_t *minishell)
{
    char *param_list[64];
    int i = 0;
    int check = 0;

    if (my_strlen(command) > 2)
        if (command[0] == '.' && command[1] == '/')
            check++;
    if (check == 0)
        return 0;
    param_list[0] = command;
    param_list[1] = NULL;
    if (run(command, param_list, minishell))
        return 1;
    return 0;
}

int execute_command(char *command, linked_list_t *env, minishell_t *minishell)
{
    if (setenv_check(env, command) == 0)
        return 0;
    if (unset_env_check(env, command) == 0)
        return 0;
    if (execve_error(command, minishell) == 1)
        return 0;
    if (execve_binary(command, minishell) == 1)
        return 0;
    minishell->return_number = find_and_run_command(command,
        minishell->path, minishell);
    return 0;
}
