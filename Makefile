# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 13:51:26 by tdelgran          #+#    #+#              #
#    Updated: 2023/06/12 12:07:26 by tdelgran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c \
		utils.c
SRCS_BONUS = server_bonus.c \
				utils_bonus.c
SRCS_CLIENT = client.c \
				utils.c
SRCS_CLIENT_BONUS = client_bonus.c \
						utils_bonus.c

OBJS_MAIN = $(SRCS:.c=.o)
OBJS_MAIN2 =$(SRCS_CLIENT:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_BONUS2 = $(SRCS_CLIENT_BONUS:.c=.o)

ifndef BONUS
OBJS = $(OBJS_MAIN)
OBJS2 = $(OBJS_MAIN2)
else
OBJS = $(OBJS_BONUS)
OBJS2 = $(OBJS_BONUS2)
endif

NAME = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
	@$(CC) $(CFLAGS) -c -I ./inc/ $< -o $(<:.c=.o)


all : $(NAME) $(NAME2)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

bonus:
	$(MAKE) BONUS=1

clean:
	rm -rf $(OBJS) $(OBJS2) $(OBJS_BONUS) $(OBJS_BONUS2)

fclean: clean
	rm -rf $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re