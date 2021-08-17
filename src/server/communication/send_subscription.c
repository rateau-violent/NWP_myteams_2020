/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** send_subscription
*/

#include "team.h"
#include "user.h"
#include "server_answer.h"

static user_t *complete_sub_list(user_t *usr, user_t *list)
{
    user_t *tmp = list;

    if (!usr)
        return list;
    if (!list) {
        list = create_empty_user();
        user_cpy(list, usr);
    }
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = create_empty_user();
        user_cpy(tmp->next, usr);
        tmp->next->prev = tmp;
    }
    return list;
}

static team_t *complete_team_list(const char *uuid, team_t *team, team_t *list)
{
    team_t *tmp = list;

    if (!team)
        return list;
    if (!get_subscriber_from_uuid(team->subscribers_list, uuid))
        return list;
    if (!list) {
        list = create_empty_team();
        team_cpy(list, team);
    }
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = create_empty_team();
        team_cpy(tmp->next, team);
        tmp->next->prev = tmp;
    }
    return list;
}

void send_team_subscribers(team_t *team, user_t *all_users, int fd,
    char *code)
{
    user_t *list = NULL;

    for (subscriber_t *tmp = team->subscribers_list; tmp; tmp = tmp->next)
        list = complete_sub_list(get_user_from_uuid(all_users, tmp->uuid),
            list);
    send_users_list(list, fd, code);
    destroy_users_list(list);
}

void send_user_subscription(user_t *user, team_t *all_teams, int fd,
    char *code)
{
    team_t *list = NULL;

    for (team_t *tmp = all_teams; tmp; tmp = tmp->next)
        list = complete_team_list(user->uuid, tmp, list);
    send_teams_list(list, fd, code);
    destroy_team_list(list);
}