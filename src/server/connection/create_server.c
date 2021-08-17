/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_server
*/

#include <stddef.h>
#include <stdlib.h>
#include "connection.h"

static server_t *create_socket(server_t *server, int port)
{
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket_fd == 1)
        return NULL;
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->addr.sin_port = htons(port);
    if (bind(server->socket_fd, (struct sockaddr *) &server->addr,
        sizeof(server->addr)) == - 1)
        return NULL;
    if (listen(server->socket_fd, 1024) == 1)
        return NULL;
    return server;
}

server_t *create_server(int port)
{
    server_t *server = calloc(1, sizeof(server_t));

    if (!server)
        return NULL;
    server = create_socket(server, port);
    if (!server) {
        free(server);
        return NULL;
    }
    FD_ZERO(&server->active_fd_set);
    FD_SET(server->socket_fd, &server->active_fd_set);
    return server;
}