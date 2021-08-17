/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_subscriber
*/

#include "subscriber.h"

#include <stdlib.h>

static void destroy_node(subscriber_t *node)
{
    if (!node)
        return;
    free(node);
}

subscriber_t *remove_subscriber_node(subscriber_t *list, const char *uuid)
{
    subscriber_t *tmp = get_subscriber_from_uuid(list, uuid);

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

subscriber_t *destroy_subscribers_list(subscriber_t *list)
{
    while (list)
        list = remove_subscriber_node(list, list->uuid);
    return NULL;
}