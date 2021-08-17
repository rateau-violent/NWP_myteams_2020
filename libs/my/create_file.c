/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_file
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int create_file(const char *filepath)
{
    if (access(filepath, F_OK) != -1)
        remove(filepath);
    return open(filepath, O_CREAT | O_APPEND | O_WRONLY,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
}