/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** user
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "server.h"
#include "client_request.h"
#include "server_answer.h"

void print_users(server_t *server, const int fd,
    const client_request_t *request)
{
    user_t *user = get_user_from_fd(server->users_list, fd);
    (void) *request;

    if (!user->logged_in)
        return send_server_answer(fd, "234", client_unauthorized, 0);
    send_users_list(server->users_list, fd, "134");
}

void get_user_info(server_t *server, const int fd,
    const client_request_t *request)
{
    user_t *user = get_user_from_fd(server->users_list, fd);
    user_t *info = get_user_from_uuid(server->users_list, request->args[0]);

    if (check_user_login(user) && info) {
        for (unsigned int it = 0; it < user->connection_nb; it++) {
            send_server_answer(user->fds[it], "133", print_user, 1);
            send_answer_data(user->fds[it], strings_to_array(2, info->uuid,
                info->username), info->logged_in, 0);
        }
    }
    else {
        send_server_answer(fd, "233", client_unauthorized, 1);
        send_answer_data(fd, strings_to_array(1, ""), 0, 0);
    }
}