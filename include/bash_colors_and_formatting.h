/*
** EPITECH PROJECT, 2020
** my_bash_colors_and_formatting
** File description:
** header
*/

#ifndef COLORS_FORMATTING_H
#define COLORS_FORMATTING_H

/************************************************/
/*                    COLORS                    */
/************************************************/

/* DEFAULT COLORS */
#define DEFAULT \e[39m
#define BLACK \e[30m
#define RED \e[31m
#define GREEN \e[32m
#define YELLOW \e[33m
#define BLUE \e[34m
#define MAGENTA \e[35m
#define CYAN \e[36m
#define WHITE \e[97m

/* LIGHT COLORS */
#define LIGHT_GRAY \e[37m
#define LIGHT_RED \e[91m
#define LIGHT_GREEN \e[92m
#define LIGHT_YELLOW \e[93m
#define LIGHT_BLUE \e[94m
#define LIGHT_MAGENTA \e[95m
#define LIGHT_CYAN \e[96m

/* DARK COLOR */
#define DARK_GRAY \e[90m

/************************************************/
/*                  BACKGROUND                  */
/************************************************/

/* DEFAULT BACKGROUND COLORS */
#define B_DEFAULT \e[49m
#define B_BLACK \e[40m
#define B_RED \e[41m
#define B_GREEN \e[42m
#define B_YELLOW \e[43m
#define B_BLUE \e[44m
#define B_MAGENTA \e[45m
#define B_CYAN \e[46m

/* LIGHT BACKGROUND COLORS */
#define B_LIGHT_GRAY \e[47m
#define B_LIGHT_RED \e[101m
#define B_LIGHT_GREEN \e[102m
#define B_LIGHT_YELLOW \e[103m
#define B_LIGHT_BLUE \e[104m
#define B_LIGHT_MAGENTA \e[105m
#define B_LIGHT_CYAN \e[106m
#define B_WHITE \e[107m

/* DARK BACKGROUND COLOR */
#define B_DARK_GRAY \e[100m

/************************************************/
/*                     SET                      */
/************************************************/

/* SET */
#define BRIGHT \e[1m
#define DIM \e[2m
#define UNDERLINED \e[4m
#define BLINK \e[5m
#define REVERSE \e[7m
#define HIDDEN \e[8m

/************************************************/
/*                    RESET                     */
/************************************************/

/* RESET */
#define RESET_ALL \e[0m
#define RESET_BRIGHT \e[21m
#define RESET_DIM \e[22m
#define RESET_UNDERLINED \e[24m
#define RESET_BLINK \e[25m
#define RESET_REVERSE \e[27m
#define RESET_HIDDEN \e[28m

#endif /*COLORS_FORMATTING_H*/
