/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_thread
*/

#include "thread.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

static thread_t *init_strings(thread_t *t, const char *author_uuid,
    const char *title, const char *message)
{
    strcpy(t->author, author_uuid);
    strcpy(t->title, title);
    strcpy(t->message, message);
    return t;
}

static thread_t *create_thread(const char *author_uuid, const char *title,
    const char *message)
{
    thread_t *new = calloc(1, sizeof(thread_t));
    char *uuid = NULL;

    if (!new)
        return NULL;
    uuid = generate_uuid();
    if (!uuid) {
        destroy_threads_list(new);
        return NULL;
    }
    new->time = time(0);
    new = init_strings(new, author_uuid, title, message);
    strcpy(new->uuid, uuid);
    free(uuid);
    if (!new->title || !new->message || !new->uuid) {
        destroy_threads_list(new);
        return NULL;
    }
    return new;
}

thread_t *create_empty_thread(void)
{
    thread_t *new = calloc(1, sizeof(thread_t));

    if (!new)
        return NULL;
    new = init_strings(new, "", "", "");
    strcpy(new->uuid, "");
    new->comments_list = create_empty_comment();
    if (!new->title || !new->message || !new->comments_list || !new->uuid) {
        destroy_threads_list(new);
        return NULL;
    }
    return new;
}

thread_t *add_thread_node(thread_t *list, const char *author_uuid,
    const char *title, const char *message)
{
    thread_t *tmp = list;

    if (!list)
        return create_thread(author_uuid, title, message);
    while (tmp->next) {
        if (!strcmp(tmp->title, title))
            return list;
        tmp = tmp->next;
    }
    tmp->next = create_thread(author_uuid, title, message);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

thread_t *thread_cpy(thread_t *t1, const thread_t *t2)
{
    if (!t1 || !t2)
        return NULL;
    strcpy(t1->title, t2->title);
    strcpy(t1->message, t2->message);
    strcpy(t1->uuid, t2->uuid);
    strcpy(t1->author, t2->author);
    t1->time = t2->time;
    return t1;
}