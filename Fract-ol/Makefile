NAME = fractol
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
FLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
SRCS =	fractol.c valid_args.c mandelbrot.c vars_init.c render.c ft_putstr.c \
		math_utils.c my_pixel_put.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

aclean: all clean

m: 
	./fractol mandelbrot

s: 
	./fractol sierpinski

vm: 
	valgrind ./fractol mandelbrot

vs: 
	valgrind ./fractol sierpinski


.PHONY: all clean fclean re
