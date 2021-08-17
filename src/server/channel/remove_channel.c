/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_channel
*/

#include "channel.h"

#include <stdlib.h>

static void destroy_node(channel_t *node)
{
    if (!node)
        return;
    if (node->threads_list)
        destroy_threads_list(node->threads_list);
    free(node);
}

channel_t *remove_channel_node(channel_t *list, const char *uuid)
{
    channel_t *tmp = get_channel_from_uuid(list, uuid);

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

channel_t *destroy_channels_list(channel_t *list)
{
    while (list)
        list = remove_channel_node(list, list->uuid);
    return NULL;
}