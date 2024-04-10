/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "../lib/my/header.h"
#include <stdbool.h>

typedef struct minishell_s {
    int return_number;
    char **path;
    int number_path;
} minishell_t;

typedef struct env_s {
    char *key;
    char *value;
} env_t;

typedef struct linked_list_s {
    env_t *env;
    struct linked_list_s *next;
} linked_list_t;

int shell(char **command, linked_list_t *env, minishell_t *minishell);
int handle_commands(char *command, linked_list_t *env, minishell_t *minishell);
int exit_command(char *command, linked_list_t *env, minishell_t *minishell);
int show_env(linked_list_t *env);
int cd_root(linked_list_t *env);
linked_list_t *initialize_env(char **env);
int cd_dir(char *path);
int cd_error(char *path, int number);
int count_words(char *str);
void free_linked_list(linked_list_t *head);
int count_tokens(const char *str, char delim);
void *setup_minishell(minishell_t *minishell, linked_list_t *env, char *path);
char *setup_path(linked_list_t *env, minishell_t *minishell);
int execute_command(char *command, linked_list_t *env, minishell_t *minishell);
char *convert_tab(char *input);
char *remove_spaces(const char *input);
void free_stuff(char *cmd_copy, char **param_list);
int fix_issue(char *str);
int execve_error(char *command, minishell_t *minishell);
int set_env(linked_list_t **env, char *key, char *value);
int setenv_check(linked_list_t *env, char *user_command);
int is_alphanumeric(char *str);
int unset_env_check(linked_list_t *env, char *user_command);
int remove_env_entry(linked_list_t **env, linked_list_t *current,
    linked_list_t *prev);
char **split_commands(char *command, int *num_commands, int semicolon_nbr);
int handle_seperator(char *command, linked_list_t *env,
    minishell_t *minishell);
int launcher(char *new_command, linked_list_t *env, minishell_t *minishell);
char *seperate_command(char *command, char **param_list);
int try_run_command_from_paths(char **paths, char **param_list,
    char *temp_command, minishell_t *minishell);
int try_run_direct_command(char *command, char **param_list,
    minishell_t *minishell);
int run(char *path_to_exec,
    char **param_list, minishell_t *minishell);
int handle_status(int status, minishell_t *minishell);
int exec_child(char *path_to_exec, char **param_list);
int path_issues(linked_list_t *env);
int simple_pipe(char *command, minishell_t *minishell);
int find_and_run_command(char *command, char **paths, minishell_t *minishell);
int run_pipe_command(char *cmd1[], char *cmd2[], minishell_t *minishell);
int create_child(char *cmd[], int *pipefd,
    minishell_t *minishell, int output);
int execute_child_process(char *cmd[], int *pipefd,
    minishell_t *minishell, int output);
char *make_string_clean(char *command);
void split_pipe(char *command, char **first_cmd,
    char **second_cmd, int pipe_index);
int launcher_pipe(char *first, char *second, minishell_t *minishell);
