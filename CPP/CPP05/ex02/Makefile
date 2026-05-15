NAME  := a.out

FLAGS := -Wall -Wextra -Werror -std=c++98
CC    := c++

SRCS  := main.cpp \
         Bureaucrat.cpp \
		 AForm.cpp \
		 ShrubberyCreationForm.cpp \
		 RobotomyRequestForm.cpp \
		 PresidentialPardonForm.cpp

HDRS  := Bureaucrat.hpp \
         AForm.hpp \
         ShrubberyCreationForm.hpp \
		 RobotomyRequestForm.hpp \
		 PresidentialPardonForm.hpp

OBJS  := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS) $(HDRS)
	$(CC) -c $(FLAGS) $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY : all clean fclean re
