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
LIB=libstack.a

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

