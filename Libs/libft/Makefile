# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/06 15:04:00 by jmunoz            #+#    #+#              #
#    Updated: 2016/10/13 19:49:17 by jmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -I Includes -Wall -Wextra -Werror
SRC=	ft_memset.c \
	 ft_bzero.c \
	 ft_memcpy.c \
	 ft_memccpy.c \
	 ft_memcmp.c \
	 ft_memmove.c \
	 ft_memchr.c \
	 ft_strlen.c \
	 ft_strdup.c \
	 ft_strdel.c \
	 ft_strcpy.c \
	 ft_strncpy.c \
	 ft_strcat.c \
	 ft_strlcat.c \
	 ft_strncat.c \
	 ft_strchr.c \
	 ft_strrchr.c \
	 ft_strstr.c \
	 ft_strnstr.c \
	 ft_strcmp.c \
	 ft_strncmp.c \
	 ft_atoi.c \
	 ft_isalpha.c \
	 ft_isdigit.c \
	 ft_isalnum.c \
	 ft_isascii.c \
	 ft_isprint.c \
	 ft_toupper.c \
	 ft_tolower.c \
	 ft_memalloc.c \
	 ft_memdel.c \
	 ft_strnew.c \
	 ft_strclr.c \
	 ft_striter.c \
	 ft_striteri.c \
	 ft_strmap.c \
	 ft_strmapi.c \
	 ft_strequ.c \
	 ft_strnequ.c \
	 ft_strsub.c \
	 ft_strjoin.c \
	 ft_strtrim.c \
	 ft_strsplit.c \
	 ft_itoa.c \
	 ft_putchar.c \
	 ft_putstr.c \
	 ft_putnbr.c \
	 ft_putendl.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putnbr_fd.c \
	 ft_putendl_fd.c \
	 ft_lstnew.c \
	 ft_lstdelone.c \
	 ft_lstdel.c \
	 ft_lstadd.c \
	 ft_lstiter.c \
	 ft_lstmap.c \
	 ft_strrev.c \
	 ft_strlenc.c \
	 ft_sqrt_low.c \
	 ft_is_prime.c \
	 ft_strnjoin.c \
	 ft_padding_right.c \
	 ft_padding_left.c \
	 ft_nbr_len.c \
	 ft_putstrn.c \
	 ft_count_char.c \
	 ft_last_separators.c\
	 ft_sort_char_tab.c\
	 get_next_line.c \
	 ft_add_tab.c \
	 ft_size_tab.c \
	 ft_path_back.c \
	 ft_strstr_count.c \
	 ft_strstrn_count.c \
	 ft_tabdup.c\
	 ft_strsplit2.c\
	 ft_lstaddback.c\
	 ft_lstcpy.c\
	 ft_freelst.c

OBJ=$(SRC:.c=.o)
NAME=libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	 	@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all
