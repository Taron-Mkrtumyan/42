NAME = minishell

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/
LIBS = -lreadline
RM = rm -rf

SRCS = src/minishell.c \
	   src/get_prompt.c \
       src/signal.c \
       src/init.c \
       src/free_minishell.c \
       src/utils/utils.c \
	   src/utils/path_utils.c \
	   src/utils/cd_utils.c \
	   src/parse/parse_input.c \
	   src/parse/parse_utils1.c \
	   src/parse/parse_utils2.c \
	   src/parse/copy_quoted.c \
	   src/parse/copy_unquoted.c \
	   src/parse/parse_utils3.c \
	   src/builtins/cd.c \
	   src/builtins/exit.c \
	   src/builtins/export.c \
	   src/builtins/env.c \
	   src/builtins/unset.c \
	   src/builtins/echo.c \
	   src/builtins/pwd.c \
	   src/execute/execute_command.c \
	   src/execute/execute_utils1.c \
	   src/execute/execute_utils2.c \
	   src/execute/execute_utils3.c \
	   src/execute/execute_utils4.c \
	   src/execute/execute_utils5.c \
	   src/utils/valid_operators.c
OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

v: all
	valgrind --track-origins=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions="readline.supp" ./minishell

.PHONY: re all clean fclean