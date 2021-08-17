/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_dir
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(size_t count, ...);

static int clean_dir(const char *name)
{
    DIR *dir = opendir(name);
    struct dirent *next_file = readdir(dir);
    char *path = NULL;

    while (next_file) {
        path = my_strcat(3, name, "/", next_file->d_name);
        remove(path);
        free(path);
        next_file = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int create_dir(const char *name)
{
    struct stat s = {0};

    if (stat(name, &s) == -1)
        return mkdir(name, 0700);
    return clean_dir(name);
}