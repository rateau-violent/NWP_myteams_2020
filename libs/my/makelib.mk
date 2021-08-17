##################################################
#                LIB OBJECTS FILES               #
##################################################

libobjects	=	$(libsources:.c=.o)

libsources	=	libs/my/my_strcat.c		\
				libs/my/create_file.c	\
				libs/my/array.c			\
				libs/my/create_dir.c

##################################################
#                   LIB OUTPUT                   #
##################################################

liboutput	=	libmy.a

##################################################
#                    LIB RULE                    #
##################################################

lib:	$(libobjects)
	@echo "$(RESET_ALL)############################$(L_BLUE) LIB COMPILATION DONE $(RESET_ALL)############################"
	@ar rc $(liboutput) $(libobjects)
	@mv libmy.a libs/
