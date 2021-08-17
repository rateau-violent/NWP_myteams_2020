/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** server_answer
*/

#include <stdlib.h>
#include <string.h>

#include "server_answer.h"

server_answer_t *create_server_answer(char *code, enum answer_header header,
    size_t read_nb)
{
    server_answer_t *answer = calloc(1, sizeof(server_answer_t));

    if (!answer)
        return NULL;
    strcpy(answer->code, code);
    answer->header = header;
    answer->read_nb = read_nb;
    return answer;
}

server_answer_t *destroy_server_answer(server_answer_t *answer)
{
    if (answer)
        free(answer);
    return NULL;
}

answer_data_t *create_answer_data(char **strings, int nb, time_t time)
{
    answer_data_t *data = calloc(1, sizeof(answer_data_t));
    size_t len = get_array_length(strings);

    if (!data)
        return NULL;
    data->nb = nb;
    data->time = time;
    strcpy(data->s1, (len > 0) ? strings[0] : "");
    strcpy(data->s2, (len > 1) ? strings[1] : "");
    strcpy(data->s3, (len > 2) ? strings[2] : "");
    strcpy(data->s4, (len > 3) ? strings[3] : "");
    destroy_array(strings);
    return data;
}

answer_data_t *destroy_answer_data(answer_data_t *data)
{
    if (data)
        free(data);
    return NULL;
}