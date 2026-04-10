NAME := HiThisIsBrain
FLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
SRC := main.cpp
OBJ := main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re
