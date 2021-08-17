/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** commands
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

bool check_user_login(const user_t *user)
{
    if (user)
        if (user->logged_in)
            return true;
    return false;
}