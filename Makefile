##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

##sources
include src/src.mk

##################################################
#                IMPLICITES RULES                #
##################################################

CC					=	gcc

RM					=	rm -rf

##################################################
#                PROCESSING FLAGS                #
##################################################

##More warning
CFLAGS				:=	-Wall
CFLAGS				+=	-Wextra

##################################################
#              PREPROCESSING FLAGS               #
##################################################

##Preprocessing flags
CPPFLAGS			:=	-Iinclude/
CPPFLAGS			+=	-Ilibs/myteams/

##################################################
#                   LIB FLAGS                    #
##################################################

LDFLAGS				:=	-Llibs/
LDFLAGS				+=	-Llibs/myteams/

LDLIBS				:=	-lmy
LDLIBS				+=	-luuid
LDLIBS				+=	-lmyteams

##################################################
#              NAME OF THE PROJECT               #
##################################################

##Binary name
output_server		=	myteams_server
output_client		=	myteams_cli

##################################################
#                   ALL RULE                     #
##################################################

%.o:	%.c
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -e "$(L_YELLOW)Compiling : $(L_CYAN)$< -> $@ $(L_GREEN)OK$(RESET_ALL)"

all:	lib $(output_server) $(output_client)

$(output_server):	$(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(output_server) $(OBJ_SERVER) $(LDLIBS) $(LDFLAGS)
	@echo -e "$(RESET_ALL)############################$(L_BLUE) SERVER COMPILATION DONE $(RESET_ALL)#########################"

$(output_client):	$(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(output_client) $(OBJ_CLIENT) $(LDLIBS) $(LDFLAGS)
	@echo -e "$(RESET_ALL)############################$(L_BLUE) CLIENT COMPILATION DONE $(RESET_ALL)#########################"

server:	$(output_server)
client: $(output_client)

##################################################
#                  INCLUDE .MK                   #
##################################################

##lib
include libs/my/makelib.mk

##tests
include tests/maketest.mk

##bash colors and formatting text
include include/bash_colors_and_formatting.mk

##################################################
#                   DEBUG RULE                   #
##################################################

##Debug with valgrind or gdb
debug:	CFLAGS += -g3 -ggdb
debug:	re

##################################################
#                 CLEANING RULES                 #
##################################################

##Clean objects files
clean:
	@$(RM) $(OBJ_CLIENT)
	@$(RM) $(OBJ_SERVER)
	@$(RM) libs/my/*.o
	@$(RM) tests/units_tests/*.o
	@$(RM) tests/*.save
	@echo -e "$(RESET_ALL)[!] $(L_RED)Cleaned objects$(RESET_ALL)     [!]"

##Clean tests files
testclean:
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) *.save
	@$(RM) libs/my/*.gcno
	@$(RM) libs/my/*.gcda
	@$(RM) tests/*.gcno
	@$(RM) tests/*.gcda
	@$(RM) tests/*.save
	@$(RM) src/*.gcno
	@$(RM) src/*.gcda
	@echo -e "$(RESET_ALL)[!] $(L_RED)Cleaned tests files$(RESET_ALL) [!]"

##Clean binary
fclean:	clean	testclean
	@$(RM) $(output_server)
	@$(RM) $(output_client)
	@$(RM) $(liboutput)
	@$(RM) $(testoutput)
	@$(RM) libs/libmy.a
	@$(RM) vgcore*
	@echo -e "$(RESET_ALL)[!] $(L_RED)Cleaned outputs$(RESET_ALL)     [!]"


##################################################
#                    RE RULE                     #
##################################################

re:	fclean all

##################################################
#                  .PHONY RULE                   #
##################################################

##Protect rules
.PHONY:	all clean testclean fclean re debug server client
