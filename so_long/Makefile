NAME := so_long

CC := cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR := srcs
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx.a 

IFLAGS := -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)

OS := $(shell uname)

ifeq ($(OS), Darwin)
	LFLAGS := -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

else ifeq ($(OS), Linux)
	LFLAGS := -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

SRCS := $(SRC_DIR)/so_long.c \
	$(SRC_DIR)/check_map.c \
	$(SRC_DIR)/errors.c \
	$(SRC_DIR)/game_images.c \
	$(SRC_DIR)/game_keys.c \
	$(SRC_DIR)/init_data.c \
	$(SRC_DIR)/keys_utils.c \
	$(SRC_DIR)/path_utils.c \
	$(SRC_DIR)/read_map.c 

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(OBJS): $(LIBFT_A) $(MLX_A)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(MLX_A):
	@if [ ! -d $(MLX_DIR)/.git ]; then \
		git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@cd $(MLX_DIR) && ./configure 
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@rm -rf $(MLX_BUILD_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re $(MLX_DIR)