# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qviguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 11:53:38 by qviguier          #+#    #+#              #
#    Updated: 2016/01/12 11:59:58 by ddevico          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC_PATH = src
SRC_NAME = 	filler.c get_next_line.c ft_util.c ft_readmap.c ft_resolve.c \
			ft_checkcoord.c

OBJ_PATH = objects

CPPFLAGS = -Iinclude

LIB_PATH = libraries
LIB_NAME = libftprintf.a

NAME = filler

CC = clang

CFLAGS = -Werror -Wall -Wextra -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@echo LINKING FILLER FROM OBJECTS FILES...
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
