/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_channel
*/

#include "channel.h"

#include <string.h>

#include <stdio.h>

channel_t *get_channel_from_name(channel_t *list, const char *name)
{
    for (; list; list = list->next)
        if (!strcmp(list->name, name))
            break;
    return list;
}

channel_t *get_channel_from_uuid(channel_t *list, const char *uuid)
{
    for (; list; list = list->next)
        if (!strcmp(list->uuid, uuid))
            break;
    return list;
}

size_t get_channels_nb(channel_t *list)
{
    size_t i = 0;

    for (channel_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}