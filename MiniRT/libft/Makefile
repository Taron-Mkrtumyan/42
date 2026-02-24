NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

# ------------------ MANDATORY ------------------

SRCS := \
	ft_isprint.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_split.c \
	ft_strmapi.c \
	ft_isalnum.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_isalpha.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_memset.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_arrlen.c \
	ft_strtod.c

OBJS := $(SRCS:.c=.o)

# ------------------ BONUS ------------------

BNSRCS := \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

BNOBJS := $(BNSRCS:.c=.o)

# ------------------ RULES ------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[1;32m✔ libft compiled\033[0m"

bonus: $(OBJS) $(BNOBJS)
	@$(AR) $(NAME) $(OBJS) $(BNOBJS)
	@echo "\033[1;32m✔ libft bonus compiled\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BNOBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus