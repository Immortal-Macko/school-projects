NAME		=	philo

SRCS		= 	main.c \
				init.c \
				routine.c \
				utils.c \
				utils2.c

OBJS		= 	$(SRCS:.c=.o)

CC			= 	gcc

FLAGS		= 	-g -Wall -Wextra -Werror -fsanitize=address

RM			= 	rm -f

all:			$(NAME)

%.o:%.c
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re