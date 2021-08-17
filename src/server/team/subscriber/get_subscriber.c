/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_subscriber
*/

#include "team.h"

#include <string.h>

subscriber_t *get_subscriber_from_uuid(subscriber_t *list, const char *uuid)
{
    for (; list; list = list->next)
        if (!strcmp(list->uuid, uuid))
            break;
    return list;
}

bool is_a_subscriber(subscriber_t *list, user_t *user)
{
    for (subscriber_t *tmp = list; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, user->uuid))
            return true;
    return false;
}