/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_comment
*/

#include "comment.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

static comment_t *create_comment(const char *uuid, const char *message)
{
    comment_t *new = calloc(1, (sizeof(comment_t)));

    if (!new)
        return NULL;
    strcpy(new->author_uuid, uuid);
    strcpy(new->message, message);
    new->time = time(0);
    return (!new->author_uuid || !new->message) ? destroy_comments_list(new) :
        new;
}

comment_t *create_empty_comment(void)
{
    comment_t *new = calloc(1, sizeof(comment_t));

    if (!new)
        return NULL;
    strcpy(new->author_uuid, "");
    strcpy(new->message, "");
    return (!new->author_uuid || !new->message) ? destroy_comments_list(new) :
        new;
}

comment_t *add_comment_node(comment_t *list, const char *username,
    const char *message)
{
    comment_t *tmp = list;

    if (!list)
        return create_comment(username, message);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_comment(username, message);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

comment_t *comment_cpy(comment_t *c1, const comment_t *c2)
{
    if (!c1 || !c2)
        return NULL;
    strcpy(c1->author_uuid, c2->author_uuid);
    strcpy(c1->message, c2->message);
    c1->time = c2->time;
    return c1;
}