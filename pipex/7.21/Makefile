NAME := pipex

SRCS := command.c \
	error.c \
	utils1.c \
	utils2.c \
	process.c \
	main.c

OBJS := $(SRCS:%.c=%.o)

HEADERS := pipex.h

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	cc -c $< -o $@ $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
