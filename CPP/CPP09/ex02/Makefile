NAME  := PmergeMe

FLAGS := -Wall -Wextra -Werror -std=c++98
CC    := c++

SRCS  := main.cpp PmergeMe.cpp
HDRS  := PmergeMe.hpp
OBJS  := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HDRS)
	$(CC) -c $(FLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY : all clean fclean re