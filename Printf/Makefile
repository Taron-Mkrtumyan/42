NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_put_u_fd.c ft_puthex_low_fd.c ft_puthex_up_fd.c ft_strlen.c ft_putptr_fd.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c Makefile ft_printf.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all, clean, fclean, re
