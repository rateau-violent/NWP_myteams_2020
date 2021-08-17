/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_discussion
*/

#include "discussion.h"

#include <stdlib.h>

static void destroy_node(discussion_t *node)
{
    if (!node)
        return;
    if (node->messages_list)
        destroy_comments_list(node->messages_list);
    free(node);
}

discussion_t *remove_discussion_node(discussion_t *list, const char *other)
{
    discussion_t *tmp = get_discussion_from_other(list, other);

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

discussion_t *destroy_discussions_list(discussion_t *list)
{
    while (list)
        list = remove_discussion_node(list, list->other_uuid);
    return NULL;
}