/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** send
*/

#include "server_answer.h"

void send_server_answer(int fd, char *code, enum answer_header header,
    size_t read_nb)
{
    server_answer_t *answer = create_server_answer(code, header, read_nb);

    if (!answer)
        return;
    write(fd, answer, sizeof(server_answer_t));
    destroy_server_answer(answer);
}

void send_answer_data(int fd, char **strings, int nb, time_t time)
{
    answer_data_t *data = create_answer_data(strings, nb, time);

    if (!data)
        return;
    write(fd, data, sizeof(*data));
    destroy_answer_data(data);
}

void send_to_user(user_t *user, void *msg, size_t msg_size)
{
    for (size_t i = 0; i < user->connection_nb; i++)
        write(user->fds[i], msg, msg_size);
}

void send_answer_to_subscribers(server_answer_t *answer, user_t *users,
    subscriber_t *sub)
{
    for (user_t *it = users; it; it = it->next)
        if (is_a_subscriber(sub, it) && it->logged_in)
            send_to_user(it, answer, sizeof(server_answer_t));
    destroy_server_answer(answer);
}

void send_data_to_subscribers(answer_data_t *data, user_t *users,
    subscriber_t *sub)
{
    for (user_t *it = users; it; it = it->next)
        if (is_a_subscriber(sub, it) && it->logged_in)
            send_to_user(it, data, sizeof(answer_data_t));
    destroy_answer_data(data);
}