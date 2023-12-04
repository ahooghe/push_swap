# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:48:33 by ahooghe           #+#    #+#              #
#    Updated: 2023/05/11 13:51:38 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -Llibstack
LDLIBS = -lft -lstack
SRC=src/free.c src/get_stack.c src/search.c src/utils.c src/utils_sort.c src/push_swap/index.c src/push_swap/move.c src/push_swap/push_swap.c src/push_swap/run.c src/push_swap/smart.c src/push_swap/sort.c src/push_swap/sort_complex.c src/push_swap/sort_small.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,free.o get_stack.o search.o utils.o utils_sort.o push_swap/index.o push_swap/move.o push_swap/push_swap.o push_swap/run.o push_swap/smart.o push_swap/sort.o push_swap/sort_complex.o push_swap/sort_small.o)
LIBFT = libft/libft.a
LIBSTACK = libstack/libstack.a
NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBSTACK)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/push_swap

$(LIBFT):
	make -C libft

$(LIBSTACK):
	make -C libstack

clean:
	rm -rf $(OBJDIR)
	make -C libft clean
	make -C libstack clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C libstack fclean

re: fclean all

