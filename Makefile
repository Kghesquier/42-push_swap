# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 14:04:27 by kghesqui          #+#    #+#              #
#    Updated: 2026/03/07 20:42:51 by kghesqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -I.
RM		:= rm -f

SRC		:=	push_swap_main.c\
			stack_utils.c\
			libft_utils.c\
			split.c\
			parser_utils.c\
			parser.c\
			swap.c\
			push.c\
			rotate.c\
			reverse_rotate.c\
			normalize.c\
			sort_utils.c\
			sort.c\
			cost.c\
			push_to_b.c\
			push_to_a.c\

OBJS	:= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re