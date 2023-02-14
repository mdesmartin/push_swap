	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:39:47 by mvogel            #+#    #+#              #
#    Updated: 2023/02/14 15:44:50 by mvogel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEADER = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = push_swap.c \
	parsing.c \
	sorting.c \
	instruct.c \
	free_n_exit.c

OBJ = $(SRC:.c=.o)

LIB_PATH = libft/

LIB_NAME = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all: lib $(NAME)

lib :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c  $(HEADER) #Makefile ?
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re lib
