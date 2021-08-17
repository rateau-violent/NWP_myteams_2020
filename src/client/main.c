/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "client.h"

static int help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\tip\tis the server ip address on wh\
ich the server socket listens\n\tport\tis the port number on which the server \
socket listens\n");
    return 0;
}

static int arguments_handling(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help"))
        return help();
    if (ac != 3) {
        printf("Invalid number of argumments given: 2 expected\n");
        return 84;
    }
    return 1;
}

int main(int ac, char **av)
{
    int r = arguments_handling(ac, av);

    if (!r)
        return (0);
    else if (r == 84)
        return (84);
    else
        run(av[1], atoi(av[2]));
    return (0);
}