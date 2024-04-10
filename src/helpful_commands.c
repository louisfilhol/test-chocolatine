/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** Minishell1
*/

#include "../includes/minishell1.h"

void count_words_bis(char *str, bool *check, int *word_count)
{
    if (*str != ' ' && !(*check)) {
        *check = true;
        (*word_count)++;
    } else if (*str == ' ' && *check) {
        *check = false;
    }
}

int count_words(char *str)
{
    int word_count = 0;
    bool check = false;

    while (*str != '\0') {
        count_words_bis(str, &check, &word_count);
        str++;
    }
    return word_count;
}

void free_linked_list(linked_list_t *head)
{
    linked_list_t *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->env->key);
        free(temp->env->value);
        free(temp->env);
        free(temp);
    }
}

char *convert_tab(char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t') {
            input[i] = ' ';
        }
    }
    return input;
}

char *remove_spaces(const char *input)
{
    char *temp_input = my_strdup(input);
    char *output = (char *)malloc(strlen(input) + 1);
    char *token;

    output[0] = '\0';
    token = strtok(temp_input, " ");
    while (token != NULL) {
        if (output[0] != '\0')
            my_strcat(output, " ");
        my_strcat(output, token);
        token = strtok(NULL, " ");
    }
    free(temp_input);
    return output;
}
