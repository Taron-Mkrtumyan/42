NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c ft_atoi.c ft_split.c ft_calloc.c ft_putendl_fd.c ft_substr.c \
       ft_strdup.c ft_strlen.c ft_strncmp.c a_init.c is_sorted.c free_stack.c \
	   free_split.c my_sort.c sorty3.c swap_ab.c rotate_ab.c reverse_rotate_ab.c \
	   push_ab.c sorty4.c

all: $(NAME)

$(NAME): $(SRCS)
	cc -g $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
.PHONY: all, clean, fclean, re
