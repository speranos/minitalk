
server = server
client = client
bonus_serv = server_bonus
bonus_clt = client_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ft_client = ./ft_client/ft_client.c
ft_server = ./ft_server/ft_server.c
ft_client_bonus = ./ft_client_bonus/ft_client_bonus.c
ft_server_bonus = ./ft_server_bonus/ft_server_bonus.c
SRC = ft_atoi.c ../ft_printf/ft_printf.c ../ft_printf/ft_lowhexa.c ../ft_printf/ft_p.c ../ft_printf/ft_putnbr.c ../ft_printf/ft_putstr.c ../ft_printf/ft_rev.c ../ft_printf/ft_uint.c ../ft_printf/ft_uphexa.c

all : ft_server ft_client

ft_server : $(server)
$(server) : $(ft_server)
	@$(CC) $(CFLAGS) $(ft_server) $(SRC) -o $(server)
	@echo SERVER IS READY !!!

ft_client : $(client)
$(client) : $(ft_client)
	@$(CC) $(CFLAGS) $(ft_client) $(SRC) -o $(client)
	@echo CLIENT IS READY !!!

bonus : ft_server_bonus ft_client_bonus

ft_server_bonus : $(bonus_serv)
$(bonus_serv) : $(ft_server_bonus)
	@$(CC) $(CFLAGS) $(ft_server_bonus) $(SRC) -o $(bonus_serv)
	@echo BONUS SERVER IS READY !!!

ft_client_bonus : $(bonus_clt)
$(bonus_clt) : $(ft_client_bonus)
	@$(CC) $(CFLAGS) $(ft_client_bonus) $(SRC) -o $(bonus_clt)
	@echo BONUS CLIENT IS READY !!!

fclean_bonus :
	@rm -rf $(bonus_serv) $(bonus_clt)
	@echo CLEAN !!!
fclean :
	@rm -rf $(client) $(server)
	@echo RESET...
re : fclean all