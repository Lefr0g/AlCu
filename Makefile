# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 14:28:50 by amulin            #+#    #+#              #
#    Updated: 2015/12/21 16:50:54 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

CC = clang

FLAGS = -Wall -Werror -Wextra

LIBFLAGS = -L libft/ -lft

LIBINCLUDIR = libft/includes/

SRCDIR = sources/

SRCS = main.c parsing.c control.c prints.c

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

OBJECTS = $(subst .c,.o,$(SRCS))

INCLUDIR = includes/

HEADERS = alum1.h

INCLUDES = $(addprefix $(INCLUDIR), $(HEADERS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIB) $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) -I $(INCLUDIR) -I $(LIBINCLUDIR) -o $(NAME) $(LIBFLAGS)

$(LIB) : subinit
	make -C libft/

clean: subinit
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: subinit fclean all

subinit :
	./git_submodules_init.sh
