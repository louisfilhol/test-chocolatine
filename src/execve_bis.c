/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int try_run_direct_command(char *command, char **param_list,
    minishell_t *minishell)
{
    int return_number;

    if (access(command, X_OK) == 0) {
        return_number = run(command, param_list, minishell);
        return return_number;
    }
    return -1;
}

int try_run_command_from_paths(char **paths, char **param_list,
    char *temp_command, minishell_t *minishell)
{
    int return_number;
    char full_path[1024];

    for (int i = 0; paths[i] != NULL; i++) {
        my_strcpy(full_path, paths[i]);
        my_strcat(full_path, "/");
        my_strcat(full_path, param_list[0]);
        if (access(full_path, X_OK) == 0) {
            param_list[0] = full_path;
            return_number = run(full_path, param_list, minishell);
            return return_number;
        }
    }
    return -1;
}

int exec_child(char *path_to_exec, char **param_list)
{
    execve(path_to_exec, param_list, NULL);
    return -1;
}

int handle_status(int status, minishell_t *minishell)
{
    if (WIFEXITED(status)) {
        minishell->return_number = WEXITSTATUS(status);
        return WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
        my_printf("Segmentation fault (core dumped)\n");
        return 1;
    }
    return 0;
}
