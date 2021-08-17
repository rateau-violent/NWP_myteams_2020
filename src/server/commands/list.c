/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** list
*/

#include "commands.h"
#include "server_answer.h"

static void list_replies(server_t *server, client_request_t *request, int fd)
{
    thread_t *thread = retrieve_thread(server->teams_list, request->team,
        request->channel, request->thread);

    if (thread)
        return send_thread_replies(thread, fd, "132");
    unknown_entity(fd, request->thread, unknown_thread);
}

static void list_threads(server_t *server, client_request_t *request, int fd)
{
    channel_t *channel = retrieve_channel(server->teams_list, request->team,
        request->channel);

    if (!channel)
        return unknown_entity(fd, request->channel, unknown_channel);
    if (request->context == in_channel)
        return send_threads_list(channel->threads_list, fd, "132");
    list_replies(server, request, fd);
}

static void list_channels(server_t *server, team_t *team,
    client_request_t *request, int fd)
{
    if (request->context == in_team)
        return send_channels_list(team->channels_list, fd, "132");
    list_threads(server, request, fd);
}

void list(server_t *server, const int fd, client_request_t *request)
{
    team_t *team = get_team_from_uuid(server->teams_list, request->team);

    if (!get_user_from_fd(server->users_list, fd)->logged_in)
        return (void)send_server_answer(fd, "232", client_unauthorized, 0);
    if (request->context == no_context)
        return;
    if (request->context == in_server)
        return send_teams_list(server->teams_list, fd, "132");
    if (!team)
        return unknown_entity(fd, request->team, unknown_team);
    if (!is_a_subscriber(team->subscribers_list,
        get_user_from_fd(server->users_list, fd)))
        return (void)send_server_answer(fd, "232", client_unauthorized,
            0);
    list_channels(server, team, request, fd);
}