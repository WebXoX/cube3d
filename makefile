# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 12:01:22 by jperinch          #+#    #+#              #
#    Updated: 2023/12/20 10:40:58 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cube3d

INC=/usr/include

INCLIB=$(INC)/../lib

# SRC = 	try5.c wall.c tile.c ray.c
SRC = 	 move_events2.c try7.c newray.c parsing.c drawline.c  #lovdev version for ray casting
# SRC = 	 move_events.c try7.c ray2.c parsing.c drawline.c  # normal version
# SRC = 	 main.c move_events.c wall.c tile.c player.c finalray.c vertical_ray.c horizontal_ray.c parsing.c drawline.c #compiled version
# SRC = ray4.c 
# SRC = 	try6.c

OBJ_DIR = obj
OS := $(shell uname)
ifeq ($(OS), Darwin)
LFLAGS = -L libft -lft -L./mlx -lmlx -L$(INCLIB) -framework OpenGL -framework AppKit
MLX_PATH_L	= ./mlx/
MLX_NAME_L	= libmlx.dylib
MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
    # Run MacOS commands
else
LFLAGS = -L libft -lft -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm 
MLX_PATH_L	= ./minilibx-linux/
MLX_NAME_L	= libmlx.a
MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)
    # Run Linux commands
endif

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -fsanitize=address -g3

CC = cc



all: $(MLX_L) $(NAME)   $(OBJ)

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
	$(CC) $(MLX_NAME_L) $(OBJ) $(CFLAGS) $(LFLAGS) -o  $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)
	@make clean -sC libft

fclean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)
	rm -rf $(MLX_NAME_L)
	@make fclean -sC libft


re:     fclean all