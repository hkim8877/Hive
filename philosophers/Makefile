NAME := philo

SRCS := main.c

OBJS := $(SRCS:%.c=%.o)

HEADERS := philosophers.h

CFLAGS = -Wall -Wextra -Werror -g

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
