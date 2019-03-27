# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstepane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 19:30:41 by dstepane          #+#    #+#              #
#    Updated: 2019/03/21 19:30:42 by dstepane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
HEAD = ./lem_in.h
SRC =	main.c \
		rooms_list.c \
		adj_list.c \
		freexit.c \
		bfs.c \
		ants_gogogo.c \
		debug.c

OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a

.PHONY: all clean fclean re

all: fclean $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[32m\033[100mLem_in executable compiled.\033[0m\033[49m"

$(LIBFT):
	@make -C libft
	@make clean -C libft 	#######

$(OBJS):
	@$(CC) $(FLAGS) -c $(SRC)
	@echo "\033[32mLem_in object files compiled.\033[0m"

clean:
	@rm -f $(OBJS)
	@make clean -C libft
	@echo "\033[31mLem_in object files removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@#	@make fclean -C libft
	@echo "\033[31mLem_in executable removed.\033[0m"

re: fclean all
