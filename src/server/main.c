/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** main
*/

#include "connection.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int help(void)
{
    printf("USAGE: ./myteams_server port\n\n\tport\tis the port number on whic\
h the server socket listens.\n");
    return 0;
}

static int arguments_handling(int ac, char **av)
{
    if (ac != 2) {
        printf("Invalid number of arguments given: 1 expected\n");
        return 84;
    }
    return (!strcmp(av[1], "-help") || !strcmp(av[1], "-h")) ? help() : 1;
}

int main(int ac, char **av)
{
    int r = arguments_handling(ac, av);

    return (r != 1) ? r : client_request(atoi(av[1]));
}