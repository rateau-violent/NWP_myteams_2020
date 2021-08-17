/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** thread
*/

#ifndef THREAD_H_
#define THREAD_H_

#include "comment.h"

#include <sys/queue.h>

typedef struct thread_s
{
    char title[MAX_NAME_LENGTH + 1];
    char message[MAX_BODY_LENGTH + 1];
    char uuid[UUID_LENGTH + 1];
    char author[UUID_LENGTH + 1];
    time_t time;
    comment_t *comments_list;
    struct thread_s *prev;
    struct thread_s *next;
} thread_t;


thread_t *add_thread_node(thread_t *list, const char *author_uuid,
    const char *title, const char *message);
thread_t *create_empty_thread(void);
thread_t *thread_cpy(thread_t *t1, const thread_t *t2);


thread_t *remove_thread_node(thread_t *list, const char *title);
thread_t *destroy_threads_list(thread_t *list);


thread_t *get_thread_from_title(thread_t *list, const char *title);
thread_t *get_thread_from_uuid(thread_t *list, const char *uuid);
size_t get_threads_nb(thread_t *list);


void save_threads_list(thread_t *list, const char *filepath);
thread_t *load_threads_list(const char *filepath);

#endif /* !THREAD_H_ */