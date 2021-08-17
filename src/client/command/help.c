/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** help
*/

#include <stdio.h>

int print_help(void)
{
    printf("/login [“user_name”]\n/logout /users\n");
    printf("/user [“user_uuid”]\n/send [“user_uuid”] [“message_body”]\n");
    printf("/messages [“user_uuid”]\n/subscribe [“team_uuid”]\n");
    printf("/subscribed ?[“team_uuid”]\n/unsubscribe [“team_uuid”]\n");
    printf("/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]\n");
    printf("/create\n/list\n/info\n");
    return 0;
}