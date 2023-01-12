# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:20:33 by mvogel            #+#    #+#              #
#    Updated: 2022/11/17 17:08:42 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRC = ft_atoi.c \
	ft_isalpha.c \
	ft_isprint.c \
    ft_memcpy.c \
    ft_strlcpy.c \
    ft_strnstr.c \
    ft_toupper.c \
    ft_bzero.c \
    ft_isascii.c \
    ft_memchr.c \
    ft_memmove.c \
    ft_strchr.c \
    ft_strlen.c \
    ft_strrchr.c \
    ft_isalnum.c \
    ft_isdigit.c \
    ft_memcmp.c \
    ft_memset.c \
    ft_strlcat.c \
    ft_strncmp.c \
    ft_tolower.c \
    ft_strdup.c \
    ft_calloc.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \

SRC_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

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
