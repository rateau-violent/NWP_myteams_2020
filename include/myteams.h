/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** myteams
*/

#ifndef MYTEAMS_H_
#define MYTEAMS_H_

#include <unistd.h>

#define MAX_NAME_LENGTH 32

#define MAX_DESCRIPTION_LENGTH 255

#define MAX_BODY_LENGTH 512

#define UUID_LENGTH 37

char *generate_uuid(void);

#endif /* !MYTEAMS_H_ */