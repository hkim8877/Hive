NAME := push_swap

SRCS := push_swap.c \
	op_1.c \
	op_2.c \
	utils.c \
	quicksort.c \
	greedy.c \
	parse_error.c \
	ft_split.c \
	main.c

OBJS := $(SRCS:%.c=%.o)

HEADERS := push_swap.h

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

.PHONY: clean fclean all re
