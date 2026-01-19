NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft -I ./
RM = rm -f

SRCS =	src/main.c \
	src/parse/init_minirt.c \
	src/parse/init_window.c \
	src/cleanup/free_minirt.c \
	src/cleanup/free_window.c \
	src/cleanup/free_arr.c \
	src/utils/utils1.c \
	src/utils/utils2.c \
	src/utils/utils3.c \
	src/utils/gnl.c \
	src/utils/gnl_utils.c \
	src/validation/validation1.c \
	src/validation/validation2.c \
	src/validation/validation3.c \
	src/math/vector_length.c

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

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

v: $(NAME)
	$(VLGRND) $(VFLAGS) ./$(NAME)

.PHONY: re all clean fclean mlx libft
