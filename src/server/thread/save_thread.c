/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_thread
*/

#include "thread.h"
#include "my.h"

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

static const char *FILE_EXTENSION = "_thread.save";

static thread_t *add_empty_node(thread_t *t)
{
    t->next = create_empty_thread();
    t->next->prev = t;
    t = t->next;
    return t;
}

static thread_t *get_comments_list(thread_t *t, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", t->uuid);

    t->comments_list = load_comments_list(full_path);
    free(full_path);
    return t;
}

static thread_t *load_loop(int fd, const char *filepath, thread_t *list)
{
    thread_t *tmp = NULL;
    thread_t buff = {0};

    while (read(fd, &buff, sizeof(thread_t)) > 0) {
        if (!list) {
            list = create_empty_thread();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_threads_list(list);
        tmp = thread_cpy(tmp, &buff);
        tmp = get_comments_list(tmp, filepath);
    }
    return list;
}

void save_threads_list(thread_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    if (full_path)
        free(full_path);
    if (fd == -1)
        return;
    for (; list; list = list->next) {
        if (!strcmp(list->uuid, ""))
            continue;
        write(fd, list, sizeof(thread_t));
        full_path = my_strcat(3, filepath, "_", list->uuid);
        if (list->comments_list)
            save_comments_list(list->comments_list, full_path);
        free(full_path);
    }
    close(fd);
}

thread_t *load_threads_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    thread_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, filepath, list);
    close(fd);
    return list;
}