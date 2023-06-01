# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 13:51:26 by tdelgran          #+#    #+#              #
#    Updated: 2023/06/01 14:53:20 by tdelgran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SOURCES = server.c client.c ft_strlen.c ft_putnbr.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o ft_putnbr.o ft_strlen.o
	$(CC) -o $@ $^
	
client: client.o ft_strlen.o
	$(CC) -o $@ $^


%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re