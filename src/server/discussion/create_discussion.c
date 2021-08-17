/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_discussion
*/

#include "discussion.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

static discussion_t *create_discussion(const char *username,
    const char *other)
{
    discussion_t *new = calloc(1, (sizeof(discussion_t)));

    if (!new)
        return NULL;
    strcpy(new->username, username);
    strcpy(new->other_uuid, other);
    if (!new->username || !new->other_uuid)
        destroy_discussions_list(new);
    return new;
}

discussion_t *create_empty_discussion(void)
{
    discussion_t *new = calloc(1, sizeof(discussion_t));

    if (!new)
        return NULL;
    strcpy(new->username, "");
    strcpy(new->other_uuid, "");
    new->messages_list = create_empty_comment();
    return (!new->username || !new->other_uuid || !new->messages_list) ?
        destroy_discussions_list(new) : new;
}

discussion_t *add_discussion_node(discussion_t *list,
    const char *username, const char *other)
{
    discussion_t *tmp = list;

    if (!list)
        return create_discussion(username, other);
    while (tmp->next) {
        if (!strcmp(other, tmp->other_uuid))
            break;
        tmp = tmp->next;
    }
    tmp->next = create_discussion(username, other);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

discussion_t *discussion_cpy(discussion_t *d1, const discussion_t *d2)
{
    if (!d1 || !d2)
        return NULL;
    strcpy(d1->username, d2->username);
    strcpy(d1->other_uuid, d2->other_uuid);
    return d1;
}