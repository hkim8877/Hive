NAME := so_long

CC := cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR := srcs
LIBFT_DIR = ./libft
MLX_DIR = ./MLX42 

LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_BUILD_DIR)/libmlx42.a

IFLAGS := -I ./include \
          -I $(LIBFT_DIR) \
          -I $(MLX_DIR)/include

OS := $(shell uname)

ifeq ($(OS), Darwin)
	LFLAGS := -L $(LIBFT_DIR) -lft \
	          -L$(MLX_BUILD_DIR) -lmlx42 \
	          -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
              -ldl -lglfw -pthread -lm 

else ifeq ($(OS), Linux)
	
	LFLAGS := -L $(LIBFT_DIR) -lft \
	          -L$(MLX_BUILD_DIR) -lmlx42 \
	          -ldl -lglfw -pthread -lm -lXext -lX11
endif

SRCS := $(SRC_DIR)/main.c \
		$(SRC_DIR)/check_map.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/game_images.c \
		$(SRC_DIR)/game_keys.c \
		$(SRC_DIR)/init_data.c \
		$(SRC_DIR)/keys_utils.c \
		$(SRC_DIR)/path_utils.c \
		$(SRC_DIR)/read_map.c \
		$(SRC_DIR)/handle_edge.c

OBJS := $(SRCS:%.c=%.o)

all: $(MLX_DIR) $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(MLFT_A) $(MLX_LIB)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(MLX_DIR):
	@git clone https://github.com/codam-coding-college/MLX42 $(MLX_DIR) || echo "MLX42 directory already exists, skipping clone."
	@cmake $(MLX_DIR) -B $(MLX_BUILD_DIR) # Use MLX_BUILD_DIR for cmake build
	@make -C $(MLX_BUILD_DIR) -j4

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