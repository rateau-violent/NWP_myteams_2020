/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** context
*/

#include "server_answer.h"
#include "commands.h"


static void channel_context(server_t *server, team_t *team, int fd,
    client_request_t *request)
{
    thread_t *thread = retrieve_thread(server->teams_list, request->team,
        request->channel, request->thread);

    if (request->context == in_channel) {
        if (!thread)
            return create_thread(server, team, fd, request);
        return (void)send_server_answer(fd, "440", error_already_exists, 0);
    }
    if (!thread)
        return unknown_entity(fd, request->thread, unknown_thread);
    return create_reply(server, team, fd, request);
}

void team_context(server_t *server, team_t *team, int fd,
    client_request_t *request)
{
    channel_t *channel = retrieve_channel(server->teams_list, request->team,
        request->channel);

    if (request->context == in_team) {
        if (!channel)
            return create_channel(server, team, fd, request);
        return (void)send_server_answer(fd, "440", error_already_exists, 0);
    }
    if (!channel)
        return unknown_entity(fd, request->channel, unknown_channel);
    return channel_context(server, team, fd, request);
}

void server_context(server_t *server, int fd, team_t *team,
    client_request_t *request)
{
    if (!team)
        return create_team(server, fd, request);
    if (team)
        send_server_answer(fd, "440", error_already_exists, 0);
}