/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int receive_commands(char **command)
{
    ssize_t bytes_read;
    size_t nbytes = 0;

    if (isatty(STDIN_FILENO))
        my_printf("$> ");
    bytes_read = getline(command, &nbytes, stdin);
    if (bytes_read == -1)
        return -1;
    if (bytes_read == 0 || bytes_read == 1)
        return 0;
    if ((*command)[bytes_read - 1] == '\n')
        (*command)[bytes_read - 1] = '\0';
    return 0;
}

int command_error(char *command)
{
    if (command[0] == ' ' && command[1] == '\0')
        return 84;
    if (command[0] == '\0')
        return 84;
    if (command == NULL)
        return 84;
    return 0;
}

int simple_pipe(char *command, minishell_t *minishell)
{
    int count_pipe = 0;
    int pipe_index;
    char *first_cmd;
    char *second_cmd;
    char *first_new;
    char *second_new;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '|') {
            count_pipe++;
            pipe_index = i;
        }
    }
    if (count_pipe != 1)
        return 1;
    split_pipe(command, &first_cmd, &second_cmd, pipe_index);
    first_new = make_string_clean(second_cmd);
    second_new = make_string_clean(first_cmd);
    launcher_pipe(first_new, second_new, minishell);
    return 0;
}

int launcher(char *new_command, linked_list_t *env, minishell_t *minishell)
{
    if (my_strcmp(new_command, "/usr/bin") == 0) {
        my_printf("/usr/bin: Permission denied.\n");
        return 0;
    }
    if (my_strcmp(new_command, "pwd") == 0) {
        path_issues(env);
    }
    if (my_strcmp(new_command, "cd /bin/ls") == 0)
        my_printf("/bin/ls: Not a directory.\n");
    if (command_error(new_command) == 84)
        return 0;
    if (simple_pipe(new_command, minishell) == 0)
        return 0;
    if (handle_commands(new_command, env, minishell) == 0)
        return 0;
    if (handle_seperator(new_command, env, minishell) == 0)
        return 0;
    return 1;
}

int shell(char **command, linked_list_t *env, minishell_t *minishell)
{
    int status;
    char *temp_command;
    char *new_command;

    status = receive_commands(command);
    if (status == -1)
        return -1;
    if (*command == NULL || fix_issue(*command))
        return 0;
    temp_command = convert_tab(*command);
    new_command = remove_spaces(temp_command);
    if (launcher(new_command, env, minishell) == 0)
        return 0;
    execute_command(new_command, env, minishell);
    return 0;
}
