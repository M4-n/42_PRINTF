# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 11:40:25 by mmaythaw          #+#    #+#              #
#    Updated: 2022/03/22 07:50:10 by mmaythaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# VARIABLES

NAME = libft.a
HEADER = libft.h
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRCM_DIR = srcm
SRCA_DIR = srca
SRCB_DIR = srcb
OBJM_DIR = objm
OBJA_DIR = obja
OBJB_DIR = objb

SRCM = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCA = ft_putnchar_fd.c ft_numlen_base.c ft_uitoa.c ft_putlstr_fd.c

SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJM = $(addprefix $(OBJM_DIR)/, $(SRCM:.c=.o))
OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))
OBJA = $(addprefix $(OBJA_DIR)/, $(SRCA:.c=.o))

# COMMANDS

SRCM_COUNT_TOT := $(shell expr $(shell echo -n $(SRCM) | wc -w) - $(shell ls -l $(OBJM_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCM_COUNT_TOT) -lt 0; echo $$?),0)
	SRCM_COUNT_TOT := $(shell echo -n $(SRCM) | wc -w)
endif
SRCM_COUNT := 0
SRCM_PCT = $(shell expr 100 \* $(SRCM_COUNT) / $(SRCM_COUNT_TOT))

SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -lt 0; echo $$?),0)
	SRCB_COUNT_TOT:=$(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

SRCA_COUNT_TOT := $(shell expr $(shell echo -n $(SRCA) | wc -w) - $(shell ls -l $(OBJA_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCA_COUNT_TOT) -lt 0; echo $$?),0)
	SRCA_COUNT_TOT:=$(shell echo -n $(SRCA) | wc -w)
endif
SRCA_COUNT := 0
SRCA_PCT = $(shell expr 100 \* $(SRCA_COUNT) / $(SRCA_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs $(OBJM) bonus additional
	@$(PRINTF) "\r%100s\r$(GREEN)$@ is up to date!$(DEFAULT)\n"

$(OBJM_DIR)/%.o: $(SRCM_DIR)/%.c
	@$(eval SRCM_COUNT = $(shell expr $(SRCM_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCM_COUNT) $(SRCM_COUNT_TOT) $(SRCM_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs $(OBJM) $(OBJB)
	@$(AR) $(NAME) $(OBJM) $(OBJB)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

additional: create_dirs $(OBJA)
	@$(AR) $(NAME) $(OBJA)

$(OBJA_DIR)/%.o: $(SRCA_DIR)/%.c
	@$(eval SRCA_COUNT = $(shell expr $(SRCA_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCA_COUNT) $(SRCA_COUNT_TOT) $(SRCA_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n"
	@$(RM) -r $(OBJM_DIR)
	@$(RM) -r $(OBJB_DIR)
	@$(RM) -r $(OBJA_DIR)

fclean: clean
	@$(RM) -r $(NAME)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

create_dirs:
	@mkdir -p $(OBJM_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(OBJA_DIR)

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRCM_DIR) $(SRCB_DIR) $(SRCA_DIR) $(HEADER)

re: fclean all

.PHONY: all bonus additional clean fclean create_dirs norminette re
