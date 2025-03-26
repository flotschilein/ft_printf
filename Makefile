# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 17:18:47 by fbraune           #+#    #+#              #
#    Updated: 2025/03/26 16:53:14 by fbraune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRC			= ft_printf.c ft_printing.c ft_printingnumbers.c
OBJ			= $(SRC:.c=.o)
RM			= rm -f

all:$(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re