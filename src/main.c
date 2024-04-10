/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

int main(int argc, char **argv, char **env)
{
    char *command = NULL;
    linked_list_t *env_new = initialize_env(env);
    minishell_t *minishell = (minishell_t *)malloc(sizeof(minishell_t));
    int status;
    char *paths;

    minishell->return_number = 0;
    paths = setup_path(env_new, minishell);
    setup_minishell(minishell, env_new, paths);
    while (1) {
        status = shell(&command, env_new, minishell);
        if (status == -1) {
            break;
        }
        free(command);
        command = NULL;
    }
    free_linked_list(env_new);
    free(minishell);
    return 0;
}
