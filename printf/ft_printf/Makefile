# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flouie <flouie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 09:15:28 by flouie            #+#    #+#              #
#    Updated: 2021/01/27 01:47:27 by flouie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wextra -Wall -Werror

NAME = libftprintf.a

HEADER = ft_printf.h

CPATH = ft_printf.c ft_parser.c ft_print_type.c ft_printf_utils.c\
		ft_printf_utils_add.c

.c.o:
	gcc $(FLAGS) -c $< -o $@

OPATH = $(CPATH:.c=.o)

all: $(NAME)

$(NAME): $(OPATH)
	ar rc $(NAME) $?
	ranlib $(NAME)

clean:
	/bin/rm -f $(OPATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
