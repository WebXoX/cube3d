NAME = cub3D

INC=/usr/include

INCLIB=$(INC)/../lib

SRC_E = event.c move_events.c rotation_events.c 
SRC_M = player.c tile.c wall.c 						
SRC_P = ceil_floor.c map.c map_validation.c 				
SRC_R = horizontal_ray.c mapray.c newray.c vertical_ray.c 
SRC_T = texture.c textureray.c 
SRC_U = drawline.c struct_init.c utils.c main.c

SRC += $(addprefix ./src/events/, $(SRC_E))
SRC += $(addprefix ./src/minimap/, $(SRC_M))
SRC += $(addprefix ./src/parsing/, $(SRC_P))
SRC += $(addprefix ./src/ray/, $(SRC_R))
SRC += $(addprefix ./src/texture/, $(SRC_T))
SRC += $(addprefix ./src/utils/, $(SRC_U))

OBJ_DIR = obj
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LFLAGS = -L libft -lft -L./mlx -lmlx -L$(INCLIB) -framework OpenGL -framework AppKit
	MLX_PATH_L	= ./mlx/
	MLX_NAME_L	= libmlx.dylib
	MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
else
	LFLAGS = -L libft -lft -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm
	MLX_PATH_L	= ./minilibx-linux/
	MLX_NAME_L	= libmlx.a
	MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
endif

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -fsanitize=address -g3

CC = cc

all: $(MLX_L) $(NAME)

$(MLX_L):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH_L)
	@make -sC libft
	cp $(MLX_L) ./

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(MLX_NAME_L) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

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
