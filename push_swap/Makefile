NAME := push_swap.a

SRCS := 

OBJS := $(SRCS:%.c=%.o)

HEADERS := push_swap.h

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(HEADERS)
	cc -c $< -o $@ $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

test: test.c
	cc $< $(NAME) -o $@
	./$@

re: fclean all

.PHONY: clean fclean all re test
