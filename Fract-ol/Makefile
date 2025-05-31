NAME = fractol
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
FLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
SRCS =	fractol.c valid_args.c mandelbrot.c vars_init.c render.c ft_putstr.c \
		math_utils.c my_pixel_put.c julia.c burning_ship.c
OBJS = $(SRCS:.c=.o)
VLGRND = valgrind 
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: mlx $(NAME)

mlx: 
	make -C$(MLX_DIR) --silent
$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c fractol.h Makefile
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
	./fractol burning_ship

j:
	./fractol julia "-0.8" "0.156"

vj:
	$(VLGRND) $(VFLAGS) ./fractol julia "-0.8" "0.156"

vm: 
	$(VLGRND) $(VFLAGS) ./fractol mandelbrot

vs: 
	$(VLGRND) $(VFLAGS) ./fractol burning_ship

.PHONY: all clean fclean re
