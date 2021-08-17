/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_discussion
*/

#include "discussion.h"

#include <string.h>

#include <stdio.h>

discussion_t *get_discussion_from_other(discussion_t *list,
    const char *other)
{
    for (; list; list = list->next)
        if (!strcmp(list->other_uuid, other))
            break;
    return list;
}

size_t get_discussions_nb(discussion_t *list)
{
    size_t i = 0;

    for (discussion_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}