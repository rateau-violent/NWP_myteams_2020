/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_thread
*/

#include "thread.h"

#include <stdlib.h>

static void destroy_node(thread_t *node)
{
    if (!node)
        return;
    if (node->comments_list)
        destroy_comments_list(node->comments_list);
    free(node);
}

thread_t *remove_thread_node(thread_t *list, const char *title)
{
    thread_t *tmp = get_thread_from_title(list, title);

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

thread_t *destroy_threads_list(thread_t *list)
{
    while (list)
        list = remove_thread_node(list, list->title);
    return NULL;
}