/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** subscribe
*/

#include "client.h"
#include "team.h"
#include "server_answer.h"
#include "server.h"
#include "client_request.h"
#include "logging_server.h"

bool team_or_user_error(team_t *team, user_t *user, int fd)
{
    if (!team || !user) {
        if (!team)
            send_server_answer(fd, "520", unknown_team, 1);
        else
            send_server_answer(fd, "520", unknown_user, 1);
        send_answer_data(fd, strings_to_array(1, team->uuid),
                        0, 0);
        return false;
    }
    return true;
}

void subscribe_team(server_t *server, const int fd, client_request_t *request)
{
    team_t *team = get_team_from_uuid(server->teams_list, request->args[0]);
    user_t *user = get_user_from_fd(server->users_list, fd);

    if (!user->logged_in)
        return send_server_answer(fd, "220", client_unauthorized, 0);
    if (!team_or_user_error(team, user, fd))
        return ;
    team->subscribers_list = add_subscriber_node
        (team->subscribers_list, user->uuid);
    server_event_user_subscribed(team->uuid, user->uuid);
    send_server_answer(fd, "120", subscribed, 1);
    send_answer_data(fd, strings_to_array(2, user->uuid, team->uuid),
        0, 0);
    return ;
}