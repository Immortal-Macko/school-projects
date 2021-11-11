# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flouie <flouie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 11:34:20 by flouie            #+#    #+#              #
#    Updated: 2020/11/24 18:16:16 by flouie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wextra -Wall -Werror

NAME = libft.a

HEADER = libft.h

CPATH = ft_strlen.c ft_strlcpy.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

BONUSC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c

.c.o:
	gcc $(FLAGS) -c $< -o $@

OPATH = $(CPATH:.c=.o)
BONUSO = $(BONUSC:.c=.o)

all: $(NAME)

$(NAME): $(OPATH)
	ar rc $(NAME) $?
	ranlib $(NAME)

bonus: $(OPATH) $(BONUSO)
	ar rc $(NAME) $(OPATH) $(BONUSO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OPATH) $(BONUSO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
