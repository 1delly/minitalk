# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 13:51:26 by tdelgran          #+#    #+#              #
#    Updated: 2023/06/07 12:45:02 by tdelgran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SOURCES = server.c client.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o utils.o
	$(CC) -o $@ $^
	
client: client.o utils.o
	$(CC) -o $@ $^


%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
fclean: clean
	rm -f server client *.o *.a

re: fclean all

.PHONY: all clean fclean re
