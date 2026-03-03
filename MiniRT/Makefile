NAME        := miniRT

SRC_DIR     := src
OBJ_DIR     := obj
HEADER_DIR  := headers

LIBFT_DIR   := libft
LIBFT_LIB   := $(LIBFT_DIR)/libft.a

MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

VLGRND      := valgrind 
VFLAGS      := --leak-check=full --show-leak-kinds=all --track-origins=yes

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3
INCLUDES    := -I./$(HEADER_DIR) -I./$(LIBFT_DIR) -I./$(MLX_DIR)
RM          := rm -f

# -------------------- SOURCES --------------------

MAIN    := main.c

PARSE   := init_minirt.c \
           init_window.c

CLEANUP := free_minirt.c \
           free_arr.c

UTILS   := utils1.c \
           utils2.c \
           utils3.c \
           utils4.c \
           gnl.c \
           is_double.c \
		   print_objs.c

VALID   := validation1.c \
           validation2.c \
           validation3.c

MATH    := vec_normalize.c \
           pixel_color.c \


# Full paths (no wildcards used)
SRCS := \
	$(addprefix $(SRC_DIR)/, $(MAIN)) \
	$(addprefix $(SRC_DIR)/parse/, $(PARSE)) \
	$(addprefix $(SRC_DIR)/cleanup/, $(CLEANUP)) \
	$(addprefix $(SRC_DIR)/utils/, $(UTILS)) \
	$(addprefix $(SRC_DIR)/validation/, $(VALID)) \
	$(addprefix $(SRC_DIR)/math/, $(MATH))

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# -------------------- COLORS --------------------

GREEN := \033[1;32m
BLUE  := \033[1;34m
RESET := \033[0m

# -------------------- RULES --------------------

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)✔ miniRT compiled$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(BLUE)Compiling$(RESET) $<\n"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) --silent
	@printf "$(GREEN)✔ minilibx compiled$(RESET)\n"


clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@$(RM) -r $(OBJ_DIR)
	@printf "$(GREEN)✔ miniRT cleaned$(RESET)\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)

re: fclean all

v: $(NAME)
	$(VLGRND) $(VFLAGS) ./$(NAME) test_scene.rt

.PHONY: all clean fclean re v