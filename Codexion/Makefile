NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

INCS = -Iincs

MAIN = codexion.c
CODERS = srcs/coders/coders.c
RUNTIME = srcs/runtime/runtime.c
SCHEDULER = srcs/scheduler/scheduler.c
UTILS = srcs/utils/errors.c srcs/utils/memory.c srcs/utils/parser.c srcs/utils/strings.c

SRCS = $(UTILS) $(CODERS) $(SCHEDULER) $(RUNTIME) $(MAIN)

OBJS = $(SRCS:%.c=%.o)
BUILD_DIR = build
COMPDB = $(BUILD_DIR)/compile_commands.json

all: $(NAME) compdb

$(NAME): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	mv $(OBJS) $(BUILD_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

compdb:
	@echo '[' > $(COMPDB)
	@first=1; \
	for src in $(SRCS); do \
			base=$(basename $$src .c); \
			obj="$(BUILD_DIR)/$$base.o"; \
			if [ $$first -eq 0 ]; then echo ',' >> $(COMPDB); fi; \
			first=0; \
			printf '  {\n' >> $(COMPDB); \
			printf '    "directory": "%s",\n' "$(CURDIR)" >> $(COMPDB); \
			printf '    "command": "$(CC) $(CFLAGS) $(INCS) -c %s -o %s",\n' "$$src" "$$obj" >> $(COMPDB); \
			printf '    "file": "%s/%s"\n' "$(CURDIR)" "$$src" >> $(COMPDB); \
			printf '  }' >> $(COMPDB); \
	done
	@echo '' >> $(COMPDB)
	@echo ']' >> $(COMPDB)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all compdb clean fclean re
