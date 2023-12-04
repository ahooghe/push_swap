# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:19:35 by ahooghe           #+#    #+#              #
#    Updated: 2023/05/11 13:19:40 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -Werror -Wextra

# Directories
OBJDIR=obj
SRCDIR=src

# Source files
SRCS=$(wildcard $(SRCDIR)/*.c)

# Object files
OBJS=$(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))

# Archive file name
LIB=libft.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

fclean: clean

re: fclean all

