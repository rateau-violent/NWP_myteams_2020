/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_server
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

#include "server.h"

void remove_server(server_t *server)
{
    destroy_users_list(server->users_list);
    destroy_team_list(server->teams_list);
    FD_CLR(server->socket_fd, &server->active_fd_set);
    FD_CLR(server->socket_fd, &server->read_fd_set);
    close(server->socket_fd);
    free(server);
}