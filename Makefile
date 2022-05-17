# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:30:52 by egunar            #+#    #+#              #
#    Updated: 2022/03/31 16:42:34 by egunar           ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

EXLIBS = libft/libft.a


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft
OFLAGS = -Wall -Wextra -Werror -Llibft -lft

all: $(NAME)

$(NAME): $(EXLIBS) $(OBJECTS)
	$(CC) $(OFLAGS) $@.o -o $@

$(EXLIBS):
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
