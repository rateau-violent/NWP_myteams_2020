/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** connection
*/

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include "server.h"

server_t *create_server(int ip);
void remove_server(server_t *server);
int client_request(int port);
int read_client(server_t *server, const int fd);

#endif
