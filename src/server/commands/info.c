/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** info
*/

#include "server.h"
#include "client_request.h"
#include "server_answer.h"

static void thread_info(server_t *server, int fd, client_request_t *request)
{
    thread_t *thread = retrieve_thread(server->teams_list, request->team,
        request->channel, request->thread);

    if (!thread)
        return unknown_entity(fd, request->thread, unknown_team);
    send_server_answer(fd, "", print_thread, 1);
    send_answer_data(fd, strings_to_array(4,
        thread->uuid, thread->author, thread->title, thread->message), 0,
        thread->time);
}

static void channel_info(server_t *server, int fd, client_request_t *request)
{
    channel_t *channel = retrieve_channel(server->teams_list, request->team,
        request->channel);

    if (!channel)
        return unknown_entity(fd, request->channel, unknown_team);
    if (request->context != in_channel)
        return thread_info(server, fd, request);
    send_server_answer(fd, "", print_channel, 1);
    send_answer_data(fd, strings_to_array(3,
        channel->uuid, channel->name, channel->description), 0, 0);
}

static void team_info(server_t *server, team_t *team, int fd,
    client_request_t *request)
{
    if (request->context != in_team)
        return channel_info(server, fd, request);
    send_server_answer(fd, "", print_team, 1);
    send_answer_data(fd, strings_to_array(3,
        team->uuid, team->name, team->description), 0, 0);
}

void info(server_t *server, const int fd, client_request_t *request)
{
    user_t *user = get_user_from_fd(server->users_list, fd);
    team_t *team = get_team_from_uuid(server->teams_list, request->team);

    if (!user->logged_in)
        return send_server_answer(fd, "231", client_unauthorized, 0);
    if (request->context == no_context)
        return;
    if (request->context == in_server) {
        send_server_answer(fd, "", print_user, 1);
        send_answer_data(fd, strings_to_array(2,
            user->uuid, user->username), user->logged_in, 0);
        return;
    }
    if (!team)
        return unknown_entity(fd, request->team, unknown_team);
    if (!is_a_subscriber(team->subscribers_list, user))
        return (void)send_server_answer(fd, "232", client_unauthorized,
            0);
    team_info(server, team, fd, request);
}