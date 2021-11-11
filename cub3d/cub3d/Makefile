FLAGS = -g -Wextra -Wall -Werror

LIBFLAGS = -framework OpenGl -framework Appkit

NAME = cub3D

CPATH = configread.c cub3d.c events.c get_next_line.c get_next_line_utils.c\
		initial_utils.c tool.c listtools.c mapcheck.c parser.c parserfunc.c\
		printfunc.c printplr.c printwalls.c utils.c

OPATH = $(CPATH:.c=.o)

BMP = bit_map.bmp

MLX = libmlx.a


all: $(NAME)

$(NAME): $(MLX) $(OPATH)
	gcc $(FLAGS) -o $(NAME) $(MLX) $(CPATH) $(LIBFLAGS)
$(MLX):
	@$(MAKE) -C mlx
	/bin/mv ./mlx/libmlx.a .

clean:
	@$(MAKE) -C mlx clean
	/bin/rm -rf $(OPATH) $(MLX) $(BMP)

fclean: clean
	/bin/rm -rf $(NAME) *.dSYM 

re: fclean all

.PHONY:	all clean fclean re