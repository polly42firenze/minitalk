# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 11:30:50 by pdi-pint          #+#    #+#              #
#    Updated: 2024/04/10 16:17:24 by pdi-pint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME) $(SERVER)
$(NAME): $(OBJ_CLIENT)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME)
$(SRC_CLIENT): $(OBJS)
	$(AR) $(SRC_CLIENT) $(OBJS)
$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)
$(SRC_SERVER): $(OBJS)
	$(AR) $(SRC_SERVER) $(OBJS)
clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make clean -C libft/
	make clean -C ft_printf/
	$(RM) $(NAME)
	$(RM) $(SERVER)

re: fclean all

.PHONY: clean fclean re all
