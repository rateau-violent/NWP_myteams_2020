/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** run
*/

#include <stdio.h>

#include "client.h"

int run(char *hostname, int port)
{
    SOCKET socket = connect_client(hostname, port);

    if (socket == 84)
        return (84);
    if (cli(socket) == 1)
        printf("CRTL-D detected quit program.\n");
    return (0);
}