/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** uuid
*/

#include <stdlib.h>
#include <uuid/uuid.h>

char *generate_uuid(void)
{
    char *uuid = calloc(UUID_STR_LEN, sizeof(char));
    uuid_t bin_uuid;

    if (!uuid)
        return NULL;
    uuid_generate_random(bin_uuid);
    uuid_unparse(bin_uuid, uuid);
    return uuid;
}
