# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 14:58:59 by jmunoz            #+#    #+#              #
#    Updated: 2016/06/29 18:30:08 by jmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

//CFLAGS= -Wall -Wextra -Werror
CFLAGS= -lncurses
CC= gcc -I Includes/
SRC= Sources/main.c\
	 Sources/move.c\
	 Sources/signals.c\
	 Sources/errors.c\
	 Sources/init.c\
	 Sources/elems.c\
	 Sources/print.c
LIBS= Libs/
OBJ= $(SRC:.c=.o)
NAME= ft_select

all: lib $(NAME)

lib:
	@make -C $(LIBS)libft

cleanlib:
	@make clean -C $(LIBS)libft

fcleanlib:
	@make fclean -C $(LIBS)libft

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -L $(LIBS)libft/ -lft

clean: cleanlib
	@rm -rf $(OBJ)

fclean: fcleanlib clean
	@rm $(NAME)

re: fclean all
