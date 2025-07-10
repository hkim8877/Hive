NAME := push_swap

SRCS := push_swap.c \
	op_1.c \
	op_2.c \
	op_3.c \
	utils_1.c \
	utils_2.c \
	utils_3.c \
	error.c \
	ft_atol.c \
	ft_split.c \
	b_to_a.c \
	partition.c \
	stack.c \
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
