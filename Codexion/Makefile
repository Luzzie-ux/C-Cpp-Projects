NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCS = incs/codexion.h

MAIN = codexion.c \
CODERS = srcs/coders/coders.c \
RUNTIME = srcs/runtime/runtime.c \
SCHEDULER = srcs/scheduler/scheduler.c \
UTILS = srcs/utils/errors.c srcs/utils/memory.c srcs/utils/parser.c srcs/utils/strings.c \

SRCS = $(UTILS) $(CODERS) $(SCHEDULER) $(RUNTIME) $(MAIN)

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
