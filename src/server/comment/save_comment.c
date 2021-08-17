/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_comment
*/

#include "comment.h"
#include "my.h"

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static const char *FILE_EXTENSION = "_comments.save";

static comment_t *add_empty_node(comment_t *comment)
{
    comment->next = create_empty_comment();
    comment->next->prev = comment;
    comment = comment->next;
    return comment;
}

static comment_t *load_loop(int fd, comment_t *list)
{
    comment_t *tmp = NULL;
    comment_t buff = {0};
    int i = 0;

    while (read(fd, &buff, sizeof(comment_t)) > 0) {
        if (!list) {
            list = create_empty_comment();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_comments_list(list);
        tmp = comment_cpy(tmp, &buff);
        i++;
    }
    return list;
}

void save_comments_list(comment_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    free(full_path);
    if (fd == -1)
        return;
    for (; list; list = list->next)
        write(fd, list, sizeof(comment_t));
    close(fd);
}

comment_t *load_comments_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    comment_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, list);
    close(fd);
    return list;
}
