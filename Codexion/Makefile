NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCS = incs/codexion.h 
SRCS = srcs/codexion.c srcs/memory.c srcs/parser.c srcs/strings.c srcs/errors.c \
		main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
