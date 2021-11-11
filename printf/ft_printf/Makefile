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
