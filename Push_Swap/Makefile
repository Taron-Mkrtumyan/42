NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c ft_atoi.c ft_split.c ft_calloc.c ft_putendl_fd.c ft_substr.c \
       ft_strdup.c ft_strlen.c ft_strncmp.c

all: $(NAME)

$(NAME): $(SRCS)
	cc $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
.PHONY: all, clean, fclean, re
