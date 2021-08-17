/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** subscribed
*/

#include <string.h>

#include "client.h"
#include "team.h"
#include "server_answer.h"
#include "server.h"
#include "client_request.h"

void subscribed_team(server_t *server, const int fd,
    client_request_t *request)
{
    team_t *team = NULL;
    user_t *user = get_user_from_fd(server->users_list, fd);

    if (!user->logged_in)
        return send_server_answer(fd, "221", client_unauthorized, 0);
    if (!strcmp(request->args[0], "")) {
        team = server->teams_list;
        send_user_subscription(user, server->teams_list, fd, "132");
    } else {
        team = get_team_from_uuid(server->teams_list, request->args[0]);
        send_team_subscribers(team, server->users_list,
            fd, "132");
    }
    return ;
}