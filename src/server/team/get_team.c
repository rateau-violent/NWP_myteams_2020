/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_team
*/

#include "team.h"

#include <string.h>

#include <stdio.h>

team_t *get_team_from_name(team_t *list, const char *name)
{
    for (; list; list = list->next)
        if (!strcmp(list->name, name))
            break;
    return list;
}

team_t *get_team_from_uuid(team_t *list, const char *uuid)
{
    for (; list; list = list->next)
        if (!strcmp(list->uuid, uuid))
            break;
    return list;
}

size_t get_teams_nb(team_t *list)
{
    size_t i = 0;

    for (team_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}