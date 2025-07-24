NAME := so_long

CC := cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS =  -lmlx -lXext -lX11
IFLAGS := -I./include -I./libft/include

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS :=  srcs/main.c \
	 \
	 \
	 \
	 \
	

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
