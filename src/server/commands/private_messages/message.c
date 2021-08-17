/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** help
*/

#include "commands.h"
#include "logging_server.h"
#include "server_answer.h"
#include "read.h"

#include <string.h>
#include <stdlib.h>

void send_private_message(server_t *server, const int fd,
    client_request_t *request)
{
    user_t *sender = get_user_from_fd(server->users_list, fd);
    user_t *receiver = get_user_from_uuid(server->users_list,
        request->args[0]);

    if (!sender->logged_in)
        return send_server_answer(fd, "210", client_unauthorized, 0);
    if (receiver && strcmp(request->args[1], "")) {
        for (size_t it = 0; it < receiver->connection_nb; it++) {
            send_server_answer(receiver->fds[it], "110",
                received_message, 1);
            send_answer_data(receiver->fds[it], strings_to_array(2,
                sender->uuid, request->args[1]), 0, 0);
        }
        save_private_messages(sender, receiver, request->args[1]);
        server_event_private_message_sended(sender->uuid,
            receiver->uuid, request->args[1]);
    } else {
        send_server_answer(fd, "211", unknown_user, 1);
        send_answer_data(fd, strings_to_array(1, request->args[0]), 0, 0);
    }
}

static void print_messages(comment_t *messages,
    const user_t *user)
{
    for (unsigned int it = 0; it < user->connection_nb; it++) {
        for (comment_t *msg = messages; msg; msg = msg->next) {
            send_server_answer(user->fds[it], "110", print_messages_list, 1);
            send_answer_data(user->fds[it], strings_to_array(2,
                msg->author_uuid, msg->message), 0,
                msg->time);
        }
    }
}

void list_messages(server_t *server, const int fd, client_request_t *request)
{
    user_t *user = get_user_from_fd(server->users_list, fd);
    discussion_t *discussion = NULL;

    if (!user->logged_in)
        return send_server_answer(fd, "211", client_unauthorized, 0);
    discussion = get_discussion_from_other(user->discussions_list,
        request->args[0]);
    if (discussion)
        print_messages(discussion->messages_list, user);
}