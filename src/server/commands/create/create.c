/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create
*/

#include <string.h>

#include "server.h"
#include "server_answer.h"
#include "commands.h"

static bool check_args(char *s1, char *s2)
{
    return (strcmp(s1, "") && strcmp(s2, ""));
}

void unknown_entity(int fd, char *uuid, enum answer_header header)
{
    send_server_answer(fd, "540", header, 1);
    send_answer_data(fd, strings_to_array(1, uuid), 0, 0);
}

static void format_args(client_request_t *request)
{
    if (strlen(request->args[0]) > MAX_NAME_LENGTH)
        request->args[0][MAX_NAME_LENGTH] = 0;
    if (strlen(request->args[1]) > MAX_DESCRIPTION_LENGTH)
        request->args[1][MAX_DESCRIPTION_LENGTH] = 0;
}

void create(server_t *server, const int fd,
    client_request_t *request)
{
    team_t *team = get_team_from_uuid(server->teams_list, request->team);

    if (!get_user_from_fd(server->users_list, fd)->logged_in)
        return (void)send_server_answer(fd, "240", client_unauthorized, 0);
    if (request->context == no_context)
        return;
    if (request->context != in_thread && !check_args(request->args[0],
        request->args[1]))
        return;
    format_args(request);
    if (request->context == in_server)
        return server_context(server, fd, team, request);
    if (!team)
        return unknown_entity(fd, request->team, unknown_team);
    if (!is_a_subscriber(team->subscribers_list,
        get_user_from_fd(server->users_list, fd)))
        return send_server_answer(fd, "240", client_unauthorized, 0);
    return team_context(server, team, fd, request);
}