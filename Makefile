# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:20:23 by oozkaya           #+#    #+#              #
#    Updated: 2018/02/20 22:31:38 by oozkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = libftprintf.a
LIBFT = libft.a

# Compilation
CC = clang
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS =
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS = -Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
	CFLAGS = -Wall -Wextra -Werror
endif
ADDFLAGS =

# Directories
SRC_PATH = srcs
OBJ_PATH = obj
LIB_PATH = libft
INC_PATH = includes/ \
		   $(LIB_PATH)/includes

# Includes & libraries
CPPFLAGS = $(addprefix -I, $(INC_PATH))
LDFLAGS = -Llibft
LDLIBS = -lft

# Sources
SRC_NAME = \
		   ft_all_printf.c\
		   ft_all_printf2.c\
		   ft_core_printf.c\
		   \
		   d_arg.c\
		   u_o_arg.c\
		   p_x_arg.c\
		   wc_c_arg.c\
		   ws_s_arg.c\
		   \
		   int_arg_tools.c\
		   unicode.c\
		   \
		   buffer.c\
		   \
		   parser.c\
		   \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

# Compilation with OS Compatibiliy
#OS = $(shell uname)
#ifeq ($(OS), Darwin)
#	CC := gcc
#	CFLAGS += -Werror -Wall -Wextra
#	ADDFLAGS += 
#endif
#ifeq ($(OS), Linux)
#	ifeq (, $(shell which clang))
#		CC := gcc
#	else
#		CC := clang
#	endif
#	CFLAGS += -Wno-unused-result
#	ADDFLAGS +=
#endif

# **************************************************************************** #
# SPECIALS CHARS                                                               #
# **************************************************************************** #
LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BOLD = \033[1m
LOG_UNDERLINE = \033[4m
LOG_BLINKING = \033[5m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

TITLE = $(LOG_CLEAR)$(LOG_BLUE)
END_TITLE = $(LOG_NOCOLOR)
LINKING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tlinking " \
				".................. $(LOG_VIOLET)$<$(LOG_NOCOLOR)"
ASSEMBLING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tassembling " \
				"............... $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
INDEXING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tindexing " \
				"................. $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
OBJECTS_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion " \
				"............ $(LOG_RED)×$(LOG_NOCOLOR)"
BIN_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion " \
				"............. $(LOG_RED)×$(LOG_NOCOLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(LIB_PATH)/$(LIBFT) $(OBJ_PATH) $(OBJ)
	@libtool -static -o $@ $(LIB_PATH)/$(LIBFT) $(OBJ)
	@ar -rc $(NAME) $(OBJ) && echo -e $(ASSEMBLING)
	@ranlib $(NAME)  && echo -e $(INDEXING)

$(LIB_PATH)/$(LIBFT):
	@make -C $(LIB_PATH)

$(OBJ_PATH):
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(ADDFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e $(LINKING)

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@make -C $(LIB_PATH) clean

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(addprefix $(INC_PATH), *.h)

test:
	@$(CC) srcs/main.c $(NAME) $(LIB_PATH)/libft.a $(CPPFLAGS) $(CFLAGS)
	@echo -e "$(TITLE) main de test$(END_TITLE)"

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : if there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
