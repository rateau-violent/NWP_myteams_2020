##################################################
#                CRITERION FLAGS                 #
##################################################

testflags	=	-lcriterion --coverage

##################################################
#                 TESTS OBJECTS                  #
##################################################

testobj		=	$(SRC:.c=.o)

testsources	=	tests/units_tests/save_tests/test_save_channel.c		\
				tests/units_tests/save_tests/test_save_comment.c		\
				tests/units_tests/save_tests/test_save_discussion.c		\
				tests/units_tests/save_tests/test_save_thread.c			\
				tests/units_tests/save_tests/test_save_team.c			\
				tests/units_tests/save_tests/test_save_subscriber.c		\
				tests/units_tests/save_tests/test_save_user.c

#tests/units_tests/test.c

##################################################
#                  TEST OUTPUT                   #
##################################################

##Test output
testoutput	=	tests_run

##################################################
#                 OBJECTS FILES                  #
##################################################

## /!\ Only .o /!\ ##
srcobj		=	src/server/user/create_user.o				\
				src/server/user/get_user.o					\
				src/server/user/remove_user.o				\
				src/server/user/save_user.o					\
				src/server/user/load_user.o					\
				src/server/channel/create_channel.o				\
				src/server/channel/get_channel.o				\
				src/server/channel/remove_channel.o				\
				src/server/channel/save_channel.o				\
				src/server/comment/create_comment.o				\
				src/server/comment/remove_comment.o				\
				src/server/comment/save_comment.o				\
				src/server/thread/create_thread.o				\
				src/server/thread/get_thread.o					\
				src/server/thread/remove_thread.o				\
				src/server/thread/save_thread.o					\
				src/server/discussion/create_discussion.o		\
				src/server/discussion/get_discussion.o			\
				src/server/discussion/remove_discussion.o		\
				src/server/discussion/save_discussion.o			\
				src/server/team/remove_team.o 					\
				src/server/team/create_team.o 					\
				src/server/team/get_team.o						\
				src/server/team/save_team.o						\
				src/server/team/load_team.o						\
				src/server/team/subscriber/create_subscriber.o	\
				src/server/team/subscriber/get_subscriber.o		\
				src/server/team/subscriber/remove_subscriber.o	\
				src/server/team/subscriber/save_subscriber.o	\
				src/server/communication/send_answer.o			\
				src/communication/server_answer.o				\
				src/server/uuid.o								\
				libs/my/my_strcat.o								\
				libs/my/create_file.o							\
				libs/my/array.o

##################################################
#                TESTS RUN RULE                  #
##################################################

tests_run:	$(srcobj) $(testobj)
	@echo -e "\e[0m[!] \e[92mCompiled object files for unit testing: OK$(RESET_ALL)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(testoutput) $(srcobj) $(testsources) $(testflags) $(LDFLAGS) -luuid -lmyteams
	@echo -e "\e[0m[i] \e[92mLinked unit tests: OK$(RESET_ALL)"
	@echo -e "\e[0m[i] \e[92mMoved gcovr files: OK$(RESET_ALL)"
	LD_LIBRARY_PATH=$(PWD)/libs/myteams/ ./$(testoutput)  | gcovr -b ; gcovr -r .
	@mv *.gcno tests
	@mv *.gcda tests
	@mv *.save tests
	@echo -e "\e[0m[i] \e[92mRunning unit test: OK$(RESET_ALL)"