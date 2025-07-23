NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread 

SRCS =	clean_all.c\
		data_init.c\
		ft_atoi.c\
		getters_and_setters.c\
		getters_setters_2.c\
		monitor.c\
		mutex_operations.c\
		philo.c\
		simulate.c\
		sinchro_utils.c\
		thread_operations.c\
		time.c\
		valid_main.c\
		write.c


OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.c filo.h Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re