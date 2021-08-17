/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** cli
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#include "server_answer.h"
#include "client_request.h"
#include "read.h"

static fd_set set_read_fd(const int socket)
{
    fd_set read_fd;

    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);
    FD_SET(socket, &read_fd);
    return read_fd;
}

static int manage_command_line(char *line, int fd, use_t *use)
{
    char *arg_line = get_argument(line, strlen(line));
    char **args = NULL;

    for (size_t i = 0; line[i]; i++)
        if (line[i] == ' ' || line[i] == '\n')
            line[i] = '\0';
    if (arg_line)
        args = get_multiple_arguments(arg_line);
    if (!strcmp(line, "/use")) {
        use = update_use(use, args);
        return 0;
    }
    if (!strcmp(line, "/help"))
        return print_help();
    send_client_request(line, args, use, fd);
    destroy_array(args);
    free(arg_line);
    return 0;
}

static int get_user_command(char *line, const int socket, use_t *use)
{
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
        return 1;
    manage_command_line(line, socket, use);
    free(line);
    return 0;
}

static int read_client(char *line, fd_set buffer_fd, const int socket,
    use_t *use)
{
    if (select(FD_SETSIZE, &buffer_fd, NULL, NULL, NULL) < 0)
        return 84;
    if (FD_ISSET(0, &buffer_fd))
        return get_user_command(line, socket, use);
    else if FD_ISSET(socket, &buffer_fd)
        if (receive_server_answer(socket) == -1)
            return -1;
    return 0;
}

int cli(int socket)
{
    char *line = NULL;
    fd_set read_fd = set_read_fd(socket);
    fd_set buffer_fd;
    int return_status = 0;
    use_t *use = calloc(1, sizeof(use_t));

    if (!use)
        return 84;
    while (!return_status) {
        buffer_fd = read_fd;
        return_status = read_client(line, buffer_fd, socket, use);
    }
    FD_CLR(0, &read_fd);
    FD_CLR(socket, &read_fd);
    free(line);
    free(use);
    return return_status;
}