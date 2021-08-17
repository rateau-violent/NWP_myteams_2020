/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** read
*/

#ifndef READ_H_
#define READ_H_

#include "user.h"

char *get_argument(const char *command, const int size);
bool check_user_login(const user_t *user);
char **get_multiple_arguments(const char *arguments);
int print_help(void);

#endif /* !READ_H_ */
