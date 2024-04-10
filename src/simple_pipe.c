/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

void split_pipe(char *command, char **first_cmd,
    char **second_cmd, int pipe_index)
{
    int right_len;

    *second_cmd = (char *)malloc(pipe_index + 1);
    my_strncpy(*second_cmd, command, pipe_index);
    (*second_cmd)[pipe_index] = '\0';
    right_len = strlen(command) - pipe_index - 1;
    *first_cmd = (char *)malloc(right_len + 1);
    my_strncpy(*first_cmd, command + pipe_index + 1, right_len);
    (*first_cmd)[right_len] = '\0';
}

char *make_string_clean(char *command)
{
    char *first_new;
    char *second_new;

    first_new = convert_tab(command);
    second_new = remove_spaces(first_new);
    return second_new;
}

int execute_child_process(char *cmd[], int *pipefd,
    minishell_t *minishell, int output)
{
    if (output) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
    }
    close(pipefd[output]);
    exit(find_and_run_command(cmd[0], minishell->path, minishell));
}

int create_child(char *cmd[], int *pipefd,
    minishell_t *minishell, int output)
{
    pid_t pid = fork();

    if (pid == -1)
        return -1;
    if (pid == 0)
        execute_child_process(cmd, pipefd, minishell, output);
    return pid;
}

int run_pipe_command(char *cmd1[], char *cmd2[], minishell_t *minishell)
{
    int pipefd[2];
    pid_t pid1;
    pid_t pid2;
    int status;

    if (pipe(pipefd) == -1)
        return -1;
    pid1 = create_child(cmd1, pipefd, minishell, 1);
    if (pid1 < 0)
        return -1;
    pid2 = create_child(cmd2, pipefd, minishell, 0);
    if (pid2 < 0)
        return -1;
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, &status, 0);
    handle_status(status, minishell);
    waitpid(pid2, &status, 0);
    return handle_status(status, minishell);
}
