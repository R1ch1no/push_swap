# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:07:48 by rkurnava          #+#    #+#              #
#    Updated: 2023/03/13 12:07:11 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC =	main.c utils.c logic.c \
		ss_rr.c pp_rrr.c \

CC = cc

DEPS = push_swap.h

CFLAGS = -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

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
