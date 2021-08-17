/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_comment
*/

#include "comment.h"

size_t get_comments_nb(comment_t *list)
{
    size_t i = 0;

    for (comment_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}

comment_t *get_last_comment(comment_t *list)
{
    comment_t *tmp = list;

    while (tmp->next)
        tmp = tmp->next;
    return tmp;
}