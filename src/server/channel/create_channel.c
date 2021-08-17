/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_channel
*/

#include "channel.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

static channel_t *create_channel(const char *name, const char *description)
{
    channel_t *new = calloc(1, sizeof(channel_t));
    char *uuid = NULL;

    if (!new)
        return NULL;
    uuid = generate_uuid();
    if (!uuid) {
        destroy_channels_list(new);
        return NULL;
    }
    strcpy(new->name, name);
    strcpy(new->description, description);
    strcpy(new->uuid, uuid);
    free(uuid);
    return (!new->name || !new->description || !new->uuid) ?
        destroy_channels_list(new) : new;
}

channel_t *create_empty_channel(void)
{
    channel_t *new = calloc(1, sizeof(channel_t));

    if (!new)
        return NULL;
    strcpy(new->name, "");
    strcpy(new->description, "");
    strcpy(new->uuid, "");
    new->threads_list = create_empty_thread();
    return (!new->name || !new->description || !new->uuid ||
        !new->threads_list) ? destroy_channels_list(new): new;
}

channel_t *add_channel_node(channel_t *list,
    const char *name, const char *description)
{
    channel_t *tmp = list;

    if (!list)
        return create_channel(name, description);
    for (; tmp->next; tmp = tmp->next)
        if (!strcmp(tmp->name, name))
            return list;
    tmp->next = create_channel(name, description);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

channel_t *channel_cpy(channel_t *c1, const channel_t *c2)
{
    if (!c1 || !c2)
        return NULL;
    strcpy(c1->name, c2->name);
    strcpy(c1->description, c2->description);
    strcpy(c1->uuid, c2->uuid);
    return c1;
}