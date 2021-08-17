/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** receive_client_request
*/

#include <string.h>

#include "commands.h"
#include "server_answer.h"

static bool check_commands(server_t *server, int fd,
    client_request_t *request)
{
    for (size_t it = 0; it < COMMANDS_NB; it++) {
        if (!strcmp(request->command, COMMANDS[it].command_name)) {
            COMMANDS[it].ft(server, fd, request);
            return true;
        }
    }
    return false;
}

int receive_client_request(server_t *server, int fd)
{
    client_request_t request = {0};

    if (read(fd, &request, sizeof(client_request_t)) < 0)
        return 84;
    if (!check_commands(server, fd, &request)) {
    }
    return 0;
}