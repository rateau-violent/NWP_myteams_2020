/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

char *my_strcat(size_t count, ...);

int create_file(const char *filepath);

char **strings_to_array(size_t count, ...);

size_t get_array_length(char **array);

void destroy_array(char **array);

int create_dir(const char *name);

#endif /* !MY_H_ */