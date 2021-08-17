/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** unsubscribe
*/

#include "client.h"
#include "team.h"
#include "server_answer.h"
#include "server.h"
#include "client_request.h"
#include "logging_server.h"

void unsubscribe_team(server_t *server, const int fd,
    client_request_t *request)
{
    team_t *team = get_team_from_uuid(server->teams_list, request->args[0]);
    user_t *user = get_user_from_fd(server->users_list, fd);

    if (!user->logged_in)
        return send_server_answer(fd, "222", client_unauthorized, 0);
    if (!team_or_user_error(team, user, fd))
        return ;
    team->subscribers_list = remove_subscriber_node
                            (team->subscribers_list, user->uuid);
    server_event_user_unsubscribed(team->uuid, user->uuid);
    send_server_answer(fd, "122", unsubscribed, 1);
    send_answer_data(fd, strings_to_array(2, user->uuid, team->uuid),
                    0, 0);
}