########################## VARIABLES ###############################

NAME			= megaphone

SRCS			= megaphone.cpp

FLAGS			= -g -Wall -Wextra -Werror -std=c++98

CC				= c++

RM				= rm -f
RM_ALL			= rm -rf

TO_CLEAN		= *.dSYM *.o *test .vscode

# ANSI escape codes for colors
GREEN	= \033[32m
RESET	= \033[0m
RED		= \e[31m
YELLOW 	= \e[33m
BLUE 	= \e[34m
MAGENTA = \e[35m
CYAN 	= \e[36m
WHITE 	= \e[37m

define PRINT_LOADING
	@printf "   -- $(RED)Compiling$(RESET) $(CYAN)$(1) $(GREEN)["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef
# @$(call PRINT_LOADING,$(NAME))

########################## TARGETS ###############################

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(ALLFLAGS) $(SRCS) -o $@

test:
	@echo "Compiling test..."
	@$(CC) $(ALLFLAGS) $(SRCS_NOMAIN) -o $@
	@echo Done!

%: $(BUILTIN_FOLDER)/%.c
	@$(CC) $(ALLFLAGS) -o $(BUILTIN_FOLDER)$@ $<

run:
	@./$(NAME)

%.o: %.c
	@echo compiling file $<...
	@$(CC) $(FLAGS) $< -o $@

clean:
	@$(RM_ALL) $(TO_CLEAN)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re test libft

###################################################################