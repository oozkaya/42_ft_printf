# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:48:02 by oozkaya           #+#    #+#              #
#    Updated: 2018/02/13 20:09:40 by oozkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = includes
SRC_DIR = ./
SRC_1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c\
		\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c\
		\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c

SRC_2 = ft_memalloc.c ft_memdel.c\
		\
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
		\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd.c \
			ft_lstdelone.c ft_lstdel.c\
			ft_lstiter.c ft_lstmap.c

SRC_EXTRA = ft_abs.c ft_capitalize.c ft_islower.c ft_isupper.c\
			ft_strlwr.c ft_strupr.c ft_strnjoin.c ft_strndup.c\
			ft_strjoinfree.c ft_strnjoinfree.c ft_strrev.c ft_itoa_base.c\
			ft_max.c ft_realloc.c get_next_line.c ft_wslen.c

SRC = $(SRC_1) $(SRC_2) $(SRC_BONUS) $(SRC_EXTRA)

OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

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

$(NAME): obj $(OBJ)
	@ar -rc $(NAME) $(OBJ) && echo -e $(ASSEMBLING)
	@ranlib $(NAME) && echo -e $(INDEXING)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo -e $(LINKING)

obj:
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@mkdir -p $(OBJ_PATH)

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)

re: fclean all
