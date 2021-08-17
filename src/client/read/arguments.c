/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** read
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "read.h"

char *get_argument(const char *command, const int size)
{
    char *argument = NULL;
    size_t command_size = 0;

    for (; command[command_size]; command_size++)
        if (command[command_size] == ' ')
            break;
    if (command_size == strlen(command))
        return NULL;
    argument = calloc(size - command_size, sizeof(char));
    if (!argument)
        return NULL;
    return strncpy(argument, command + command_size + 1, size -
        command_size - 2);
}

static size_t get_nb_arguments(const char *arguments)
{
    size_t nb_arguments = 0;
    size_t quotes = 0;

    for (size_t it = 0; arguments[it]; it++) {
        if (arguments[it] == '"')
            quotes += 1;
        if (quotes == 2) {
            nb_arguments += 1;
            quotes = 0;
        }
    }
    return nb_arguments;
}

static size_t *get_arguments_size(const char *arguments)
{
    size_t *arguments_size = NULL;
    size_t nb_arguments = get_nb_arguments(arguments);
    size_t size = 1;
    size_t quotes = 0;

    arguments_size = calloc(nb_arguments + 2, sizeof(size_t));
    if (!arguments_size) return NULL;
    arguments_size[0] = nb_arguments;
    nb_arguments = 0;
    for (size_t it = 0; arguments[it]; it++) {
        if (arguments[it] == '"' && quotes == 1) {
            arguments_size[++nb_arguments] = size - 1;
            size = 0;
            quotes = 0;
        } else if (arguments[it] == '"') quotes += 1;
        else size += 1;
    }
    arguments_size[nb_arguments + 1] = size;
    return arguments_size;
}

static char **concatenate_arguments(const char *argument, size_t *argument_size,
    char **arguments)
{
    size_t concatenate_size = 1;

    for (size_t it = 0; it < argument_size[0]; it++) {
        strncpy(arguments[it], argument + concatenate_size,
            argument_size[it + 1]);
        concatenate_size += argument_size[it + 1] + 3;
    }
    return arguments;
}

char **get_multiple_arguments(const char *argument)
{
    char **arguments = NULL;
    size_t *argument_size = NULL;

    argument_size = get_arguments_size(argument);
    if (!argument_size)
        return NULL;
    arguments = calloc(argument_size[0] + 1, sizeof(char *));
    if (!arguments)
        return NULL;
    for (size_t it = 0; it < argument_size[0]; it++) {
        arguments[it] = calloc(argument_size[it + 1] + 1, sizeof(char));
        if (!arguments[it])
            return NULL;
    }
    arguments = concatenate_arguments(argument, argument_size, arguments);
    free(argument_size);
    return arguments;
}