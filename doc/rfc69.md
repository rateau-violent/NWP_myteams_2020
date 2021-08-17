%%%
title = "My Teams RFC Protocol"
abbrev = "My Teams RFC Protocol"
ipr= "trust200902"
area = "Internet"
workgroup = "Network Working Group"
submissiontype = "IETF"
keyword = [""]
date = 2021-05-20T00:00:00Z

[seriesInfo]
name = "RFC"
value = "69"
stream = "IETF"
status = "standard"

[[author]]
initials="V."
surname="Rabeau"
fullname="Victoire Rabeau"
organization = "Epitech"
  [author.address]
  email = "victoire.rabeau@epitech.eu"
  [author.address.postal]
  city = "Paris"
[[author]]
initials="T."
surname="Gozard"
fullname="Théodore Gozard"
organization = "Epitech"
  [author.address]
  email = "theodore1.gozard@epitech.eu"
  [author.address.postal]
  city = "Paris"
[[author]]
initials="G."
surname="Ye"
fullname="Guillaume Ye"
organization = "Epitech"
  [author.address]
  email = "guillaume.ye@epitech.eu"
  [author.address.postal]
  city = "Paris"
%%%

.# Abstract

First RFC protocol

{mainmatter}

# Introduction

Second project of Network module during second year at Epitech Paris.
Date: 03 / 05 / 2021, 08:00 ---> 06 / 06 / 2021, 23:42

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

# My Teams protocol
Request protocol : TCP

Why TCP and not UDP ?
For sure TCP is slower than UDP but we always want package to arrive to destination and we don't want to have packet loss. But in a case of voice package we can use UDP protocol because we want fast transfer and packet loss is not a problem.

We use binary protocol (in bits) to send struct.

## How work our Teams ?
1. Client send a struct to server
2. Server receives a command and execute it
3. Server send in return a header with data struct size then data struct
4. Client can receives one or multiple struct
5. Client call function to print info in terminal

# My Teams server return code

First number | Explanation     | Second number | Explanation  | Third number                      | Explanation
-------------|-----------------|---------------|--------------|-----------------------------------|----------------------------------------
[1]          | No error        | [0]           | Log          | [0] / [1]                         | Login / Logout
[2]          | Acess denied    | [1]           | Messages     | [0] / [1]                         | Send / Message
[3]          | Invalid command | [2]           | Subscription | [0] / [1] / [2]                   | Subscribe / Subscribed /Unsubscribe
[4]          | Argument error  | [3]           | Informations | [0] / [1] / [2] / [3] / [4] / [5] | Use / Info / List / User / Users /Help
[5]          | Uuid not found  | [4]           | Creation     | [0]                               | Create
Table: My Teams server return  code

# My teams client commands

Commands                                               | Explanation
-------------------------------------------------------|---------------------------------------------------------------------------------------
/help                                                  | show help
/login ["user_name"]                                   | set the user_name used by client
/logout                                                | disconnect the client from the server
/users                                                 | get the list of all users that exist on the domain
/user ["user_uuid"]                                    | get information about a user
/send ["user_uuid"] ["message_body"]                   | send a message to a user
/messages ["user_uuid"]                                | list all messages exchange with an user
/subscribe ["team_uuid"]                               | subscribe to the event of a team and its sub directories (enable reception of all events from a team)
/subscribed ?["team_uuid"]                             | list all subscribed teams or list all users subscribed to a team
/unsubscribe ["team_uuid"]                             | unsubscribe from a team
/use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"] | use specify a context team/channel/thread
/create ["team_name"] ["team_description"]             | when the context is not defined create a new team
/create ["channel_name"] ["channel_description"]       | when team_uuid is defined create a new channel
/create ["thread_title"] ["thread_message"]            | when team_uuid and channel_uuid are defined create a new thread
/create ["comment_body"]                               | when team_uuid, channel_uuid and thread_uuid are defined create a new reply
/list                                                  | when the context is not defined list all existing teams
/list                                                  | when team_uuid is definedlist all existing channels
/list                                                  | when team_uuid and channel_uuid are defined list all existing threads
/list                                                  | when team_uuid, channel_uuid and thread_uuid are defined list all existing replies
/info                                                  | when the context is not defined display currently logged user infos
/info                                                  | when team_uuid is defined display currently selected team infos
/info                                                  | when team_uuid and channel_uuid are defined display currently selected channel infos
/info                                                  | when team_uuid, channel_uuid and thread_uuid are defined display currently selected thread infos

Table: My teams client commands

{backmatter}