# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:39:47 by mvogel            #+#    #+#              #
#    Updated: 2023/01/25 16:44:11 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	parsing.c \
	sorting.c \
	instruct.c

OBJ = $(SRC:.c=.o)

LIB_PATH = libft/

LIB_NAME = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all: $(NAME)

lib :
	make -C $(LIB_PATH)

$(NAME): $(OBJ) lib
	$(CC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re lib
