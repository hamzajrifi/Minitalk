CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = header.h
NAME = mainitalk.a
SRV_NAME = server.a
CC_FILES = 	client.c \
			function.c
CS_FILES = server.c
OC_FILES = 	client.o \
			function.o
OS_FILES = server.o

all : CLN SRV

CLN:$(NAME)
$(NAME) : $(OC_FILES) $(HEADER)
	@$(CC) $(FLAGS) -c $(CC_FILES)
	@ar -rc $(NAME) $(OC_FILES)
	@$(CC) -o client client.c $(NAME)

SRV : $(SRV_NAME)
$(SRV_NAME) : $(OS_FILES) $(HEADER)
	@$(CC)  $(FLAGS) -c $(CS_FILES) 
	@ar -rc $(SRV_NAME) $(OS_FILES)
	@$(CC) -o server server.c $(SRV_NAME)
clean 	:
	rm -f *.o 
fclean 	: clean
	rm -f $(NAME) client server $(SRV_NAME) $(NAME)
re 		: fclean all