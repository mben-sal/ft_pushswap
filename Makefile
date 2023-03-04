# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:49:52 by mben-sal          #+#    #+#              #
#    Updated: 2023/03/02 20:39:36 by mben-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRC = ./main.c\
		./utils/ft_atoi.c\
		./utils/ft_isdigit.c\
		./utils/ft_printf.c\
		./utils/ft_split.c\
		./utils/ft_strdup.c\
		./utils/ft_strjoin.c\
		./utils/ft_strlen.c\
		./utils/ft_strncmp.c\
		./ft_alloc.c\
		./ft_arr.c\
		./ft_cinq_num.c\
		./ft_stack.c\
		./ft_group.c\
		./ft_push_stack.c\
		./ft_sortir_stack_b.c\
		./ft_mouvement_stack_a_b.c\
		./ft_sortir.c


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc


all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all