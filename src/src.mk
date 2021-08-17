##################################################
#              SERVER OBJECTS FILES              #
##################################################

OBJ_SERVER				=	$(SRC_SERVER:.c=.o)

SRC_SERVER				=	src/server/main.c									\
							src/server/user/create_user.c						\
							src/server/user/get_user.c							\
							src/server/user/remove_user.c						\
							src/server/user/save_user.c							\
							src/server/user/load_user.c							\
							src/server/user/fd_management.c						\
							src/server/channel/create_channel.c					\
							src/server/channel/get_channel.c					\
							src/server/channel/remove_channel.c					\
							src/server/channel/save_channel.c					\
							src/server/comment/create_comment.c					\
							src/server/comment/remove_comment.c					\
							src/server/comment/get_comment.c					\
							src/server/comment/save_comment.c					\
							src/server/thread/create_thread.c					\
							src/server/thread/get_thread.c						\
							src/server/thread/remove_thread.c					\
							src/server/thread/save_thread.c						\
							src/server/discussion/create_discussion.c			\
							src/server/discussion/get_discussion.c				\
							src/server/discussion/remove_discussion.c			\
							src/server/discussion/save_discussion.c				\
							src/server/connection/create_server.c 				\
							src/server/connection/connection.c 					\
							src/server/remove_server.c 							\
							src/server/team/remove_team.c 						\
							src/server/team/create_team.c 						\
							src/server/team/save_team.c 						\
							src/server/team/load_team.c 						\
							src/server/team/get_team.c							\
							src/server/team/subscriber/create_subscriber.c		\
							src/server/team/subscriber/get_subscriber.c			\
							src/server/team/subscriber/remove_subscriber.c		\
							src/server/team/subscriber/save_subscriber.c		\
							src/server/uuid.c									\
							src/server/save.c									\
							src/server/commands/authentification.c				\
							src/server/commands/user.c							\
							src/server/commands/commands.c						\
							src/server/commands/retrieve_entities.c				\
							src/server/commands/list.c							\
							src/server/commands/info.c							\
							src/server/commands/create/create.c					\
							src/server/commands/create/create_entities.c		\
							src/server/commands/create/context.c				\
							src/server/commands/subscribe.c						\
							src/server/commands/unsubscribe.c					\
							src/server/commands/subscribed.c					\
							src/communication/server_answer.c					\
							src/server/communication/send_answer.c				\
							src/server/communication/send_subscription.c		\
							src/server/communication/send_entities_list.c		\
							src/server/communication/send_discussion.c			\
							src/server/communication/receive_client_request.c	\
							src/server/commands/private_messages/message.c		\
							src/server/commands/private_messages/save_private_messages.c

##################################################
#              CLIENT OBJECTS FILES              #
##################################################

OBJ_CLIENT				=	$(SRC_CLIENT:.c=.o)

SRC_CLIENT				=	src/client/main.c								\
							src/client/client.c								\
							src/client/run.c								\
							src/client/cli.c								\
							src/client/communication/receive_answer.c		\
							src/client/communication/send_request.c			\
							src/client/command/use.c						\
							src/server/user/create_user.c					\
							src/server/user/remove_user.c					\
							src/server/user/get_user.c						\
							src/server/discussion/remove_discussion.c		\
							src/server/discussion/create_discussion.c		\
							src/server/discussion/get_discussion.c			\
							src/server/comment/create_comment.c				\
							src/server/comment/remove_comment.c				\
							src/server/uuid.c								\
							src/communication/server_answer.c				\
							src/client/read/arguments.c						\
							src/client/command/help.c
