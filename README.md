# 1. Project name: My Teams

# 2. Description:
    The goal of this project is to create a server and a CLI client.
    The network communication will be achieved through the use of TCP sockets.

    A collaborative communication application is a service able to manage severall communication teams, where discussion are organised like following:
        • threads (initial post and additional comments) in a specific channel
        • discussion (personnal messages)

    Here are the features we implemented:
        • Creating/Joining/Leaving a team
        • Creating a user
        • Creating a channel in a team
        • Creating a thread in a channel
        • Creating a comment in a thread
        • Saving & restoring users, teams, channels, threads & associated comments
        • Personnal discussion (from a user to an other)
        • Saving & restoring personnal discussion

    Please note that all arguments of the existing commands should be quoted with double quotes.
    A missing quote should be interpreted as an error.
    Please note that all the names, descriptions and message bodies have a pre-defined length which will be as follow:
        • MAX_NAME_LENGTH 32
        • MAX_DESCRIPTION_LENGTH 255
        • MAX_BODY_LENGTH 512

# 3. Table of contents
1. [Usage](#usage)
2. [Requirements](#requirements)
3. [Getting Started](#getting-started)
4. [Credits](#credits)

# 4. Usage:
```
    ./myteams_server –help
    USAGE: LD_LIBRARY_PATH=$(pwd)/libs/myteams/ ./myteams_server port

        port    is the port number on which the server socket listens.

    ./myteams_cli -help
    USAGE: LD_LIBRARY_PATH=$(pwd)/libs/myteams/ ./myteams_cli ip port

        ip      is the server ip address on which the server socket listens
        port    is the port number on which the server socket listens
```

# 5. Requirements

## 5.1. Server
- [x] Creating/Joining/Leaving a team
- [x] Creating a user
- [x] Creating a channel in a team
- [x] Creating a thread in a channel
- [x] Creating a comment in a thread
- [x] Saving & restoring users, teams, channels, threads & associated comments
- [x] Personnal discussion (from a user to an other)
- [x] Saving & restoring personnal discussion

## 5.2. client
- [ ] help : show help
- [x] login ["user_name"] : set the user_name used by client
- [x] logout : disconnect the client from the server
- [x] users : get the list of all users that exist on the domain
- [x] user ["user_uuid"] : get information about a user
- [x] send ["user_uuid"] ["message_body"] : send a message to a user
- [x] messages ["user_uuid"] : list all messages exchange with an user
- [x] subscribe ["team_uuid"] : subscribe to the event of a team and its sub directories (enable reception of all events from a team)
- [x] subscribed ?["team_uuid"] : list all subscribed teams or list all users subscribed to a team
- [x] unsubscribe ["team_uuid"] : unsubscribe from a team
- [x] use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"] : use specify a context team/channel/thread
- [x] create : based on what is being used create the sub resource (see below)
- [x] list : based on what is being used list all the sub resources (see below)
- [x] info : based on what is being used list the current (see below)

# 6. Getting Started:
```
    Open two terminals

    First terminal:
    $ LD_LIBRARY_PATH=$(pwd)/libs/myteams/ ./myteams_server port

    Second terminal:
    $ LD_LIBRARY_PATH=$(pwd)/libs/myteams/ ./myteams_cli ip port

    With two laptops you can start a server with the first laptop and connect with the second laptop. (Don't forget to change localhost by a IP)
```

# 7. Credits:

- [Victoire Rabeau](https://github.com/Victoire-Rabeau) | <victoire.rabeau@epitech.eu>
- [Théodore Gozard](https://github.com/TheodoreGozard) | <theodore1.gozard@epitech.eu>
- [Guillaume Ye](https://github.com/Myuw) | <guillaume.ye@epitech.eu>
