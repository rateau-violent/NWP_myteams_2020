/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** client
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"
#include "my.h"

static int error_handler(char *msg)
{
    printf("%s\n", msg);
    free(msg);
    return 84;
}

int connect_client(char *hostname, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *hostinfo = NULL;
    SOCKADDR_IN sin = { 0 };

    if (sock == INVALID_SOCKET)
        return error_handler(my_strcat(1, "Error: socket()\n"));
    hostinfo = gethostbyname(hostname);
    if (!hostinfo)
        return error_handler(my_strcat(2, "Unknown host ", hostname));
    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;
    if (connect(sock, (SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
        return error_handler(my_strcat(1, "Error: connect()"));
    return (sock);
}