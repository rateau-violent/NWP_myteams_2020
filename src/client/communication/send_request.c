/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** send_request
*/

#include <stdlib.h>
#include <string.h>

#include "client_request.h"

static enum user_context get_context(const use_t *use)
{
    if (!use)
        return no_context;
    if (!strcmp(use->team, ""))
        return in_server;
    if (strcmp(use->team, "") && !strcmp(use->channel, ""))
        return in_team;
    return (strcmp(use->team, "")
        && strcmp(use->channel, "")
        && !strcmp(use->thread, "")) ? in_channel : in_thread;
}

static client_request_t *create_client_request(const char *command,
    char **args, const use_t *use)
{
    client_request_t *request = calloc(1, sizeof(client_request_t));
    size_t args_nb = get_array_length(args);
    size_t i = 0;

    if (!request)
        return NULL;
    strcpy(request->command, command);
    for (; i < 4; i++) {
        if (i < args_nb && strlen(args[i]) > MAX_BODY_LENGTH)
            args[i][MAX_BODY_LENGTH] = 0;
        strcpy(request->args[i], (i < args_nb) ? args[i] : "");
    }
    strcpy(request->team, use->team);
    strcpy(request->channel, use->channel);
    strcpy(request->thread, use->thread);
    request->context = get_context(use);
    request->close_fd = true;
    return request;
}

void send_client_request(const char *command, char **args, const use_t *use,
    int fd)
{
    client_request_t *request = create_client_request(command, args, use);

    if (!request)
        return;
    write(fd, request, sizeof(client_request_t));
    free(request);
}