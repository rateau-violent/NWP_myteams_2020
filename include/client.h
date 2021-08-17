/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;


int run(char *hostname, int port);
int connect_client(char *hostname, int port);
int cli(int socket);

#endif /* !CLIENT_H_ */


