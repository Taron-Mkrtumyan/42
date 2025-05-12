NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRCS =	pipex.c ft_calloc.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c \
		ft_strjoin.c cmds_init.c free_split.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	cc -g $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	cc -g $(FLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
