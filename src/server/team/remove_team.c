/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_team
*/

#include "team.h"

#include <stdlib.h>

static void destroy_node(team_t *node)
{
    if (!node)
        return;
    if (node->channels_list)
        destroy_channels_list(node->channels_list);
    if (node->subscribers_list)
        destroy_subscribers_list(node->subscribers_list);
    free(node);
}

team_t *remove_team_node(team_t *list, const char *name)
{
    team_t *tmp = get_team_from_name(list, name);

    if (!tmp)
        return list;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp == list)
        list = list->next;
    destroy_node(tmp);
    return list;
}

team_t *destroy_team_list(team_t *list)
{
    while (list)
        list = remove_team_node(list, list->name);
    return NULL;
}