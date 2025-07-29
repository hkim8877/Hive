NAME := so_long

CC := cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR := srcs
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_LIB := $(MLX_DIR)/libmlx.a

IFLAGS := -I ./include \
          -I $(LIBFT_DIR) \
          -I $(MLX_DIR)

OS := $(shell uname)

ifeq ($(OS), Darwin)
	LFLAGS := -L $(LIBFT_DIR) -lft \
	           -L $(MLX_DIR) -lmlx \
	           -framework OpenGL -framework AppKit

else ifeq ($(OS), Linux)
	
	LFLAGS := -L $(LIBFT_DIR) -lft \
	           -L $(MLX_DIR) -lmlx \
	           -lXext -lX11 -lm -lz
endif

SRCS := $(wildcard $(SRC_DIR)/*.c)	

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_LIB)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)
$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
