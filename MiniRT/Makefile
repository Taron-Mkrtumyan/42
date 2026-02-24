NAME        := miniRT

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -I./ -I./libft -I./minilibx-linux
RM          := rm -f

SRC_DIR     := src
OBJ_DIR     := obj

LIBFT_DIR   := libft
LIBFT_LIB   := $(LIBFT_DIR)/libft.a

MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

VLGRND      := valgrind 
VFLAGS      := --leak-check=full --show-leak-kinds=all --track-origins=yes

# -------------------- SOURCES --------------------

MAIN    := main.c

PARSE   := init_minirt.c \
           init_window.c

CLEANUP := free_minirt.c \
           free_window.c \
           free_arr.c

UTILS   := utils1.c \
           utils2.c \
           utils3.c \
           utils4.c \
           gnl.c \
           gnl_utils.c \
           is_double.c

VALID   := validation1.c \
           validation2.c \
           validation3.c

MATH    := vectors.c

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
	@echo "$(GREEN)✔ miniRT compiled$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling$(RESET) $<"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) --silent
	@echo "$(GREEN)✔ minilibx compiled$(RESET)"


clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)✔ miniRT cleaned$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)

re: fclean all

v: $(NAME)
	$(VLGRND) $(VFLAGS) ./$(NAME)

.PHONY: all clean fclean re