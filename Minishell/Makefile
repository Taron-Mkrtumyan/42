NAME = minishell

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror -I Libft/
LIBS = -lreadline

SRCS =	main.c clean_all.c ft_exit.c data_init.c 
OBJS = $(SRCS:.c=.o)

VLGRND = valgrind 
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(LIBFT): 
	make -C $(LIBFT_DIR) --silent

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBS)

%.o: %.c minishell.h Makefile
	cc $(FLAGS) -c $< -o $@ 

clean:
	$(MAKE) clean -C $(LIBFT_DIR) --silent
	rm -f $(OBJS)

fclean: 
	$(MAKE) fclean -C $(LIBFT_DIR) --silent
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all

v: all
	$(VLGRND) $(VFLAGS) ./$(NAME)  

.PHONY: all clean fclean re
