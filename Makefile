
server = server
client = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ft_client = ./ft_client/ft_client.c
ft_server = ./ft_server/ft_server.c
SRC = ft_atoi.c ft_putstr.c

all : ft_server ft_client
ft_server : $(server)
$(server) : $(ft_server)
	@$(CC) $(CFLAGS) $(ft_server) $(SRC) -o $(server)
	@echo SERVER IS READY !!!
ft_client : $(client)
$(client) : $(ft_client)
	@$(CC) $(CFLAGS) $(ft_client) $(SRC) -o $(client)
	@echo CLIENT IS READY !!!
clean :
	@rm -rf $(client) $(server)
	@echo CLEAN !!!
fclean :
	@rm -rf $(client) $(server)
	@echo RESET...
re : fclean all