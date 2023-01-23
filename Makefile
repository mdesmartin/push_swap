# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:39:47 by mvogel            #+#    #+#              #
#    Updated: 2023/01/23 15:59:20 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRC = push_swap.c \
	parsing.c \
	sorting.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
