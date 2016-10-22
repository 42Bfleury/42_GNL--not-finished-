# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/05 00:15:13 by bfleury           #+#    #+#              #
#    Updated: 2016/10/05 09:29:49 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= GNL
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

SRC		= get_next_line.c \
		  main.c

OBJ		= $(SRC:.c=.o)

$(NAME):
		make -C libft fclean && make -C libft
		$(CC) $(CFLAGS) -I libft/includes -o get_next_line.o -c get_next_line.c
		$(CC) $(CFLAGS) -I libft/includes -o main.o -c main.c
		$(CC) -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

all:	$(NAME)

clean:
		make -C libft clean
		rm -f $(OBJ)

fclean:	clean
		make -C libft fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:	clean fclean
