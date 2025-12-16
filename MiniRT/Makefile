NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/
RM = rm -rf

SRCS =	Srcs/main.c

OBJS = ${SRCS:.c=.o}

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

VLGRND = valgrind 
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBS)

mlx:
	make -C$(MLX_DIR) --silent

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
