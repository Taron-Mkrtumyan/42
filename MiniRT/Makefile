NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft -I ./
RM = rm -f

SRCS =	src/main.c \
	src/parse/init_minirt.c \
	src/parse/init_window.c \
	src/validation/validation.c

OBJS = ${SRCS:.c=.o}

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -I$(MLX_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

VLGRND = valgrind 
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: mlx libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

libft: 
	$(MAKE) -C $(LIBFT_DIR) --silent

mlx:
	make -C $(MLX_DIR) --silent

clean:
	$(MAKE) clean -C $(LIBFT_DIR) 
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) 
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean mlx libft
