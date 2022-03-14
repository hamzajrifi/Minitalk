CC = gcc -fsanitize=address

CFLAGS =  -Wall -Wextra -Werror 

HEADER = header.h

NAME = mainitalk.a

SRV_NAME = server.a

CC_FILES = 	client.c \
			checker.c \
			function.c

CS_FILES = 	server.c \
			checker.c \
			function.c

OC_FILES = 	client.o \
			checker.o \
			function.o

OS_FILES = 	server.o \
			checker.o \
			function.o

all : CLN SRV

CLN:$(NAME)
$(NAME) : $(OC_FILES) $(HEADER)
	@$(CC) $(FLAGS) -c $(CC_FILES)
	@ar -rc $(NAME) $(OC_FILES)
	@$(CC) -o client client.c $(NAME)

SRV : $(SRV_NAME)
$(SRV_NAME) : $(OS_FILES) $(HEADER)
	@$(CC) $(CFLAGS) -c $(CS_FILES) 
	@ar -rc $(SRV_NAME) $(OS_FILES)
	@$(CC) -o server server.c $(SRV_NAME)

clean 	:
	rm -f *.o 

fclean 	: clean
	rm -f $(NAME) client server $(SRV_NAME) $(NAME) $(BNS_C_NAME) $(BNS_S_NAME) client_bonus server_bonus a.out

re 		: fclean all
#----------------------- part bonus ---------------------------/
BNS_C_NAME = client_bonus.a

BNS_S_NAME = server_bonus.a

HEADER_bns = header_bonus.h

BNS_CC_FLIES =	client_bonus.c \
				checker_bonus.c \
				function_bonus.c 

BNS_SC_FLIES =	server_bonus.c \
				checker_bonus.c \
				function_bonus.c 

BNS_OC_FLIES =	client_bonus.o \
				checker_bonus.o \
				function_bonus.o 

BNS_OS_FILES = 	server_bonus.o \
				checker_bonus.o \
				function_bonus.o

bonus :	BNS_CLN BNS_SRV

BNS_CLN	: $(BNS_C_NAME)
$(BNS_C_NAME) : $(BNS_OC_FLIES) $(HEADER_BNS)
	$(CC) $(CFLAGS) $(BNS_CC_FLIES)
	ar -rc $(BNS_C_NAME) $(BNS_OC_FLIES)
	$(CC) -o client_bonus client_bonus.c $(BNS_C_NAME)

BNS_SRV	: $(BNS_S_NAME)
$(BNS_S_NAME) : $(BNS_OS_FILES) $(HEADER_BNS)
	$(CC) $(CFLAGS) $(BNS_SC_FLIES)
	ar -rc $(BNS_S_NAME) $(BNS_OS_FILES)
	$(CC) -o server_bonus server_bonus.c $(BNS_S_NAME)
