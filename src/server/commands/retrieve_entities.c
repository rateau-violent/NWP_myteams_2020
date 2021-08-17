/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** retrieve_entities
*/

#include "team.h"

channel_t *retrieve_channel(team_t *teams_list, const char *team_uuid,
    const char *channel_uuid)
{
    team_t *team = get_team_from_uuid(teams_list, team_uuid);

    return (!team) ? NULL : get_channel_from_uuid(team->channels_list,
        channel_uuid);
}

thread_t *retrieve_thread(team_t *teams_list, const char *team_uuid,
    const char *channel_uuid, const char *thread_uuid)
{
    channel_t *channel = retrieve_channel(teams_list, team_uuid,
        channel_uuid);

    return (!channel) ? NULL : get_thread_from_uuid(channel->threads_list,
        thread_uuid);
}