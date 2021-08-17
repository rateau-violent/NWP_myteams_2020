/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** receive_answer
*/

#include <string.h>
#include "server_answer.h"

static int print2(enum answer_header header, answer_data_t *d)
{
    for (size_t i = 0; i < PRINT_USER_SIZE; i++)
        if (header == PRINT_USER[i].header)
            return PRINT_USER[i].user(d->s1, d->s2, d->nb);
    for (size_t i = 0; i < PRINT_MESSAGES_LIST_SIZE; i++)
        if (header == PRINT_MESSAGES_LIST[i].header)
            return PRINT_MESSAGES_LIST[i].messages(d->s1, d->time, d->s2);
    for (size_t i = 0; i < PRINT_COMMENT_SIZE; i++)
        if (header == PRINT_COMMENT[i].header)
            return PRINT_COMMENT[i].comment(d->s1, d->s2, d->time, d->s3);
    for (size_t i = 0; i < THREAD_EVENTS_SIZE; i++)
        if (header == THREAD_EVENTS[i].header)
            return THREAD_EVENTS[i].event(d->s1, d->s2, d->time, d->s3,
                d->s4);
    return 84;
}

static int print(enum answer_header header, answer_data_t *d)
{
    for (size_t i = 0; i < CLIENT_ERRORS_SIZE; i++)
        if (header == CLIENT_ERRORS[i].header)
            return CLIENT_ERRORS[i].error();
    if (!d)
        return 0;
    for (size_t i = 0; i < UNKNOWN_ENTITY_ERRORS_SIZE; i++)
        if (header == UNKNOWN_ENTITY_ERRORS[i].header)
            return UNKNOWN_ENTITY_ERRORS[i].error(d->s1);
    for (size_t i = 0; i < NOTIFICATION_EVENTS_SIZE; i++)
        if (header == NOTIFICATION_EVENTS[i].header)
            return NOTIFICATION_EVENTS[i].notif(d->s1, d->s2);
    for (size_t i = 0; i < CREATED_EVENTS_SIZE; i++)
        if (header == CREATED_EVENTS[i].header)
            return CREATED_EVENTS[i].created(d->s1, d->s2, d->s3);
    for (size_t i = 0; i < REPLY_RECEIVED_SIZE; i++)
        if (header == REPLY_RECEIVED[i].header)
            return REPLY_RECEIVED[i].reply(d->s1, d->s2, d->s3, d->s4);
    return print2(header, d);
}

static int receive_data_loop(int fd, server_answer_t *answer)
{
    answer_data_t buff = {0};

    if (!answer->read_nb)
        return print(answer->header, NULL);
    for (size_t i = 0; i < answer->read_nb; i++) {
        if (read(fd, &buff, sizeof(answer_data_t)) < 0)
            return 84;
        print(answer->header, &buff);
    }
    if (answer->header == logged_out &&
        !strcmp(answer->code, "101"))
        return -1;
    return 0;
}

int receive_server_answer(int fd)
{
    server_answer_t answer = {0};

    if (read(fd, &answer, sizeof(server_answer_t)) == -1)
        return 84;
    return receive_data_loop(fd, &answer);
}