/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** use
*/

#include <string.h>
#include <stdio.h>

#include "client_request.h"

use_t *reset_use(use_t *use)
{
    if (!use)
        return NULL;
    strcpy(use->team, "");
    strcpy(use->channel, "");
    strcpy(use->thread, "");
    return use;
}

use_t *update_use(use_t *use, char **args)
{
    size_t args_nb = get_array_length(args);

    for (size_t i = 0; i < args_nb; i++)
        if (strlen(args[i]) > UUID_LENGTH) {
            printf("/use error: Invalid argument format\n");
            return use;
        }
    strcpy(use->team, (args_nb > 0) ? args[0] : "");
    strcpy(use->channel, (args_nb > 1) ? args[1] : "");
    strcpy(use->thread, (args_nb > 2) ? args[2] : "");
    return use;
}