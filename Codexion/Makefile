NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCS = incs

MAIN = codexion.c
CODERS = srcs/coders/coders.c
RUNTIME = srcs/runtime/runtime.c
SCHEDULER = srcs/scheduler/scheduler.c
UTILS = srcs/utils/errors.c srcs/utils/memory.c srcs/utils/parser.c srcs/utils/strings.c

SRCS = $(UTILS) $(CODERS) $(SCHEDULER) $(RUNTIME) $(MAIN)

OBJS = $(SRCS:.c=.o)
BUILD_DIR = build
COMPDB = $(BUILD_DIR)/compile_commands.json

all: $(NAME) compdb

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

compdb:
	@mkdir -p $(BUILD_DIR)
	@echo '[' > $(COMPDB)
	@first=1; \
	for src in $(SRCS); do \
			obj=$${src%.c}.o; \
			if [ $$first -eq 0 ]; then echo ',' >> $(COMPDB); fi; \
			first=0; \
			printf '  {\n' >> $(COMPDB); \
			printf '    "directory": "%s",\n' "$(CURDIR)" >> $(COMPDB); \
			printf '    "command": "$(CC) $(CFLAGS) -I$(INCS) -c %s -o %s",\n' "$$src" "$$obj" >> $(COMPDB); \
			printf '    "file": "%s/%s"\n' "$(CURDIR)" "$$src" >> $(COMPDB); \
			printf '  },' >> $(COMPDB); \
	done; \
	echo '' >> $(COMPDB); \
	echo ']' >> $(COMPDB)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all compdb clean fclean re
