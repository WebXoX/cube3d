# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 12:01:22 by jperinch          #+#    #+#              #
#    Updated: 2023/11/14 09:30:45 by afarheen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cube3d

INC=/usr/include

INCLIB=$(INC)/../lib

SRC = 	try.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -fsanitize=address -g3
# LFLAGS = -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -fsanitize=address
LFLAGS = -L./mlx -lmlx -L$(INCLIB) -framework OpenGL -framework AppKit

CC = gcc

MLX_PATH_L	= ./mlx/
MLX_NAME_L	= libmlx.dylib
MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)

# MLX_PATH_L	= ./minilibx-linux/
# MLX_NAME_L	= libmlx.a
# MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)

all: $(MLX_L) $(NAME)   $(OBJ)

$(MLX_L):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH_L)
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

fclean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)
	rm -rf $(MLX_NAME_L)


re:     fclean all