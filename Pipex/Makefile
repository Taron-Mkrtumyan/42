NAME = pipex
FLAGS = -Wall -Wextra #-Werror
SRCS =	pipex.c ft_calloc.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c \
		ft_strjoin.c cmds_init.c

all: $(NAME)

$(NAME): $(SRCS)
	cc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
.PHONY: all, clean, fclean, re
