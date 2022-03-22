# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 08:54:59 by mmaythaw          #+#    #+#              #
#    Updated: 2022/03/22 07:03:33 by mmaythaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

# VARIABLES
NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRCM_DIR = srcm
SRCB_DIR = srcb
OBJM_DIR = objm
OBJB_DIR = objb
LIBFT = libft/libft.a
PRINTF = LC_NUMERIC="en_US.UTF-8" printf

SRCM = ft_printf.c newformat.c check_flag.c 1convert.c 2convert.c 3convert.c
SRCB = ft_printf_bonus.c newformat_bonus.c check_flag_bonus.c 1convert_bonus.c 2convert_bonus.c 3convert_bonus.c

OBJM = $(addprefix $(OBJM_DIR)/, $(SRCM:.c=.o))
OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

# COMMANDS
SRCM_COUNT_TOT := $(shell expr $(shell echo -n $(SRCM) | wc -w) - $(shell ls -l $(OBJM_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCM_COUNT_TOT) -le 0; echo $$?),0)
	SRCM_COUNT_TOT := $(shell echo -n $(SRCM) | wc -w)
endif
SRCM_COUNT := 0
SRCM_PCT = $(shell expr 100 \* $(SRCM_COUNT) / $(SRCM_COUNT_TOT))

SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
 ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJM)
	@$(AR) $@ $(OBJM)
	@$(PRINTF) "\r%100s\r$(GREEN)$@ is up to date!$(DEFAULT)\n"

$(OBJM_DIR)/%.o: $(SRCM_DIR)/%.c
	@$(eval SRCM_COUNT = $(shell expr $(SRCM_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCM_COUNT) $(SRCM_COUNT_TOT) $(SRCM_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_libft $(OBJB)
	@$(AR) $(NAME) $(OBJB)
	@$(PRINTF) "\r%100s\r$(GREEN)$@ is up to date!$(DEFAULT)\n"

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then git clone https://github.com/M4-n/42_LIBFT.git libft; fi
	@make all -C libft
	@cp $(LIBFT) $(NAME)

create_dirs:
	@mkdir -p $(OBJM_DIR)
	@mkdir -p $(OBJB_DIR)

test: all
	@$(PRINTF) "\n$(YELLOW)Testing with test/main.c$(DEFAULT)\n\n"
	@$(CC) -c test/main.c
	@$(CC) main.o $(NAME)
	@./a.out $(UNAME) | cat -e
	@$(RM) main.o a.out
	@$(PRINTF) "$(GREEN)Test done$(DEFULT)\n"

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files...$(DEFAULT)\n"
	@if [ -d "libft" ]; then make clean -C libft; fi
	@if [ -f "main.d" ]; then $(RM) main.d; fi
	@$(RM) -r $(OBJM_DIR)
	@$(RM) -r $(OBJB_DIR)

fclean: clean
	@$(RM) -r $(NAME)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@if [ -d "libft" ]; then $(RM) $(LIBFT); fi
	@if [ ! -d "libft" ]; then $(PRINTF) "$(CYAN)Removed libft.a$(DEFAULT)\n"; fi

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for ft_printf...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRCM_DIR) $(SRCB_DIR) $(HEADER)
	@if [ -d "libft" ]; then make norminette -C libft; fi
	@$(PRINTF) "$(GREEN)\nChecking norm completed !$(DEFAULT)\n"

re: fclean all

.PHONY: all clean fclean re $(NAME) bonus compile_libft create_dirs test norminette
