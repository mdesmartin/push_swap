# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:39:47 by mvogel            #+#    #+#              #
#    Updated: 2023/02/20 15:14:50 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HDR_PATH = include/

HDR_LST = push_swap.h

HDR = $(addprefix $(HDR_PATH), $(HDR_LST))

SRC_PATH = src/

SRC_LST = push_swap.c \
		parsing.c \
		sorting.c \
		instruct.c \
		free_n_exit.c

SRC = $(addprefix $(SRC_PATH), $(SRC_LST))

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(HDR_PATH)

##

all: libft
	$(MAKE) $(NAME)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

libft :
	$(MAKE) -C $(LIBFT_PATH)

##

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all libft clean fclean re
 