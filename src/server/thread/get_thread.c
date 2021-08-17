/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_thread
*/

#include "thread.h"

#include <string.h>

#include <stdio.h>

thread_t *get_thread_from_title(thread_t *list, const char *title)
{
    for (; list; list = list->next)
        if (!strcmp(list->title, title))
            break;
    return list;
}

thread_t *get_thread_from_uuid(thread_t *list, const char *uuid)
{
    for (; list; list = list->next)
        if (!strcmp(list->uuid, uuid))
            break;
    return list;
}

size_t get_threads_nb(thread_t *list)
{
    size_t i = 0;

    for (thread_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}