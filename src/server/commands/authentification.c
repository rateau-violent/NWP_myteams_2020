/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** login
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "client_request.h"
#include "server_answer.h"
#include "my.h"
#include "logging_server.h"

static void user_logging_event
    (server_t *server, user_t *user, server_answer_t *answer)
{
    answer_data_t *data = create_answer_data(
        strings_to_array(2, user->uuid, user->username), 0, 0);

    for (user_t *it = server->users_list; it; it = it->next) {
        send_to_user(it, answer, sizeof(server_answer_t));
        send_to_user(it, data, sizeof(answer_data_t));
    }
    destroy_server_answer(answer);
    destroy_answer_data(data);
}

static void multiple_login(server_t *server, const int fd, user_t *user)
{
    server_event_user_logged_out(user->uuid);
    send_server_answer(fd, "000", logged_out, 1);
    send_answer_data(fd, strings_to_array(2, user->uuid, user->username),
        0, 0);
    user_logging_event
        (server, user, create_server_answer("101", logged_in, 1));
    server_event_user_logged_in(user->uuid);
}

static void check_user_exist(server_t *server, const int fd,
    client_request_t *request)
{
    char *username = request->args[0];
    user_t *user = get_user_from_username(server->users_list, username);
    if (user) {
        if (user->logged_in)
            return multiple_login(server, fd, user);
        server->users_list = remove_user_node_from_fd(server->users_list, fd);
        user = add_fd_to_user(user, fd);
        if (!user)
            return;
    } else {
        user = get_user_from_fd(server->users_list, fd);
        strcpy(user->username, username);
        server_event_user_created(user->uuid, user->username);
    }
    user->logged_in = true;
    user_logging_event
        (server, user, create_server_answer("101", logged_in, 1));
    server_event_user_logged_in(user->uuid);
}

void logout_user(server_t *server, const int fd, client_request_t *request)
{
    user_t *user = get_user_from_fd(server->users_list, fd);

    if (!user->logged_in)
        return send_server_answer(fd, "201", client_unauthorized, 0);
    if (user) {
        server_event_user_logged_out(user->uuid);
        send_server_answer(fd, "101", logged_out, 1);
        send_answer_data(fd, strings_to_array(2, user->uuid, user->username),
            0, 0);
        user = remove_fd_from_user(user, fd);
        user->logged_in = false;
        if (request->close_fd) {
            close(fd);
            FD_CLR(fd, &server->active_fd_set);
        }
    }
}

void login_user(server_t *server, const int fd, client_request_t *request)
{
    if (!request->args || !strcmp(request->args[0], ""))
        send_server_answer(fd, "200", client_unauthorized, 0);
    if (strlen(request->args[0]) > MAX_NAME_LENGTH)
        request->args[0][MAX_NAME_LENGTH] = 0;
    check_user_exist(server, fd, request);
}