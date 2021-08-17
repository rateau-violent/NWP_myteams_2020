/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** connection
*/

#include <stddef.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "connection.h"
#include "client_request.h"

static int keep_running = 1;

static void sigint_handler(int keep_running)
{
    (void) keep_running;
    keep_running = 0;
}

static int handle_new_connection(server_t *server, const int client_fd)
{
    socklen_t size = sizeof(server);
    int acpt = accept(client_fd, (struct sockaddr *)
        &server->addr, (socklen_t *) &size);

    if (acpt == -1)
        return 84;
    server->users_list = add_user_node(server->users_list, acpt);
    FD_SET(acpt, &server->active_fd_set);
    dprintf(acpt, "%d\n", 220);
    return 0;
}

static int check_connection(server_t *server, const int client_fd)
{
    if (FD_ISSET(client_fd, &server->read_fd_set))
        return (client_fd == server->socket_fd) ?
            handle_new_connection(server, client_fd) :
            receive_client_request(server, client_fd);
    return 0;
}

static int check_client(server_t *server, const int keep_running)
{
    if (select(FD_SETSIZE, &server->read_fd_set, NULL, NULL, NULL) < 0)
        return (keep_running) ? 1 : 84;
    for (size_t it = 0; it < FD_SETSIZE; it++)
        if (check_connection(server, it) == 84)
            return 84;
    return 0;
}

int client_request(int port)
{
    server_t *server = create_server(port);
    size_t return_status = 0;

    if (!server)
        return 84;
    server = load_server_data(server);
    signal(SIGINT, sigint_handler);
    while (keep_running) {
        server->read_fd_set = server->active_fd_set;
        return_status = check_client(server, keep_running);
        if (return_status)
            break;
    }
    save_server_data(server);
    remove_server(server);
    if (return_status == 84)
        return 84;
    return 0;
}
