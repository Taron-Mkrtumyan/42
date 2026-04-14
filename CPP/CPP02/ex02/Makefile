NAME := a.out
FLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
SRC := Fixed.cpp main.cpp
OBJ := $(SRC:.cpp=.o)
HEADER := Fixed.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ): $(SRC) $(HEADER)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re
