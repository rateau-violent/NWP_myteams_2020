/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_comment
*/

#include "comment.h"

#include <stdlib.h>

static void destroy_node(comment_t *node)
{
    if (!node)
        return;
    free(node);
}

comment_t *remove_last_comment(comment_t *list)
{
    comment_t *tmp = list;

    if (!list)
        return NULL;
    while (tmp && tmp->next)
        tmp = tmp->next;
    if (tmp == list)
        list = list->next;
    else
        tmp->prev->next = NULL;
    destroy_node(tmp);
    return list;
}

comment_t *destroy_comments_list(comment_t *list)
{
    (void)list;
    return NULL;
}