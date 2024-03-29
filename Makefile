# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:07:48 by rkurnava          #+#    #+#              #
#    Updated: 2023/03/19 14:06:48 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC =	main.c utils.c logic.c \
		ss_rr.c pp_rrr.c \
		small_sort.c\

CC = cc

DEPS = push_swap.h

CFLAGS = -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)
	@echo "$(NAME) created"

all : $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Objects and $(NAME) deleted"

fclean : clean
	@rm -f $(NAME)

re : fclean all
