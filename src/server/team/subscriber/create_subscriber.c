/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** subscribers
*/

#include "team.h"

#include <stdlib.h>
#include <string.h>

static subscriber_t *create_subscriber(const char *uuid)
{
    subscriber_t *new = calloc(1, sizeof(subscriber_t));

    if (!new)
        return NULL;
    strcpy(new->uuid, uuid);
    return new;
}

subscriber_t *create_empty_subscriber(void)
{
    subscriber_t *new = calloc(1, sizeof(subscriber_t));

    if (!new)
        return NULL;
    strcpy(new->uuid, "");
    return (!new->uuid) ? NULL : new;
}

subscriber_t *add_subscriber_node(subscriber_t *list, const char *uuid)
{
    subscriber_t *tmp = list;

    if (!list)
        return create_subscriber(uuid);
    for (; tmp->next; tmp = tmp->next)
        if (!strcmp(tmp->uuid, uuid))
            return list;
    tmp->next = create_subscriber(uuid);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

subscriber_t *subscriber_cpy(subscriber_t *s1, const subscriber_t *s2)
{
    if (!s1 || !s2)
        return NULL;
    strcpy(s1->uuid, s2->uuid);
    return s1;
}