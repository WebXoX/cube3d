NAME = cub3D

INC = /usr/include
INCLIB = $(INC)/../lib

SRC_E = event.c move_events.c rotation_events.c 
SRC_M = player.c tile.c wall.c 						
SRC_P = ceil_floor.c map.c map_validation.c 				
SRC_R = horizontal_ray.c mapray.c newray.c vertical_ray.c 
SRC_T = texture.c textureray.c 
SRC_U = drawline.c struct_init.c utils.c main.c

SRC = $(addprefix events/, $(SRC_E)) \
      $(addprefix minimap/, $(SRC_M)) \
      $(addprefix parsing/, $(SRC_P)) \
      $(addprefix ray/, $(SRC_R)) \
      $(addprefix textures/, $(SRC_T)) \
      $(addprefix utils/, $(SRC_U))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

OS := $(shell uname)
ifeq ($(OS), Darwin)
    LFLAGS = -Llibft -lft -L./mlx -lmlx -L$(INCLIB) -framework OpenGL -framework AppKit
    MLX_PATH_L	= ./mlx/
    MLX_NAME_L	= libmlx.dylib
    MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
else
    LFLAGS = -Llibft -lft -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm
    MLX_PATH_L	= ./minilibx-linux/
    MLX_NAME_L	= libmlx.a
    MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
endif

CFLAGS = -Wall -Wextra -Werror  -g3
CC = gcc

all: $(MLX_L) $(OBJ_DIR) $(NAME)

$(MLX_L):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH_L)
	@make -sC libft
	cp $(MLX_L) ./


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: ./src/events/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ./src/minimap/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ./src/parsing/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ./src/ray/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@	

$(OBJ_DIR)/%.o: ./src/textures/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ./src/utils/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)
	@make clean -sC libft

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	@make clean -sC $(MLX_PATH_L)
	rm -rf $(MLX_NAME_L)
	@make fclean -sC libft

re: fclean all
