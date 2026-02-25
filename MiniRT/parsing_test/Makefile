NAME		= miniRT

CC			= cc
CFLAGS = -Wall -Wextra -Werror $(INC)

INC			= -Isrc \
			  -Isrc/libft \
			  -Isrc/get_next_line \
			  -Iminilibx-linux

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/validation/validation.c \
	   $(SRC_DIR)/validation/validation2.c \
	   $(SRC_DIR)/validation/validation3.c \
	   $(SRC_DIR)/validation/utils1.c \
	   $(SRC_DIR)/validation/utils2.c \
	   $(SRC_DIR)/validation/utils3.c \
	   $(SRC_DIR)/validation/utils4.c \
       $(SRC_DIR)/parse/init_minirt.c \
       $(SRC_DIR)/parse/init_window.c \
       $(SRC_DIR)/stubs.c \
	   $(SRC_DIR)/cleanup/free_minirt.c \
	   $(SRC_DIR)/vector/vec1.c \
	   $(SRC_DIR)/print_objs.c \
       $(wildcard $(SRC_DIR)/libft/*.c) \
       $(wildcard $(SRC_DIR)/get_next_line/*.c)

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
