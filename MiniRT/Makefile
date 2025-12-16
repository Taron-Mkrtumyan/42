NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

SRCS =	src/main.c \
	$(wildcard src/libft/*.c)

OBJS = ${SRCS:.c=.o}

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -I$(MLX_DIR)

INCLUDES = -I src -I src/libft

VLGRND = valgrind 
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: mlx $(NAME)


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mlx:
	make -C $(MLX_DIR) --silent

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean mlx
