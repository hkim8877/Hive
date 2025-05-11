NAME := libftprintf.a

SRCS :=

OBJS := $(SRCS:%.c=%.o)

HEADERS := ft_printf.h

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

re: fclean all

.PHONY: clean fclean all re