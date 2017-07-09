# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qviguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 11:53:38 by qviguier          #+#    #+#              #
#    Updated: 2016/01/07 13:16:02 by qviguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, norminette

SRC_PATH = src
SRC_NAME = centering.c checkinput.c ft_lstdup.c ft_realloc.c ft_validate.c \
		main.c mmu_mmanager.c mmu_writer.c mmu_writer2.c resolve.c resolve2.c

OBJ_PATH = objects

CPPFLAGS = -Iinclude

LIB_PATH = libraries
LIB_NAME = libft.a

NAME = fillit

CC = clang

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

all: $(NAME)

$(NAME): norminette $(OBJ_NAME)
	@echo LINKING FILLIT FROM OBJECTS FILES...
	@$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIB)
	@echo SUCCESS !

$(OBJ_NAME):
	@echo COMPILING $(@)...
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC_PATH)/$(@:.o=.c) -o $(OBJ_PATH)/$(@) -c \
	$<

clean:
	@rm -f $(OBJ)
	@echo OBJECTS FILES DELETION COMPLETE !
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo EXECUTABLE DELETED !

re: fclean all

norminette:
	@echo --------------------------------------------------------------------
	@norminette $(SRC)
	@echo --------------------------------------------------------------------
