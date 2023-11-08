# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 12:01:22 by jperinch          #+#    #+#              #
#    Updated: 2023/11/08 09:25:26 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cube3d

INC=/usr/include

INCLIB=$(INC)/../lib

SRC = 	walls.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# CFLAGS =  -Wall -Wextra -Werror 
LFLAGS = -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -fsanitize=address

CC = gcc

MLX_PATH	= ./mlx/
MLX_NAME	= libmlx.dylib
MLX			= $(MLX_PATH)$(MLX_NAME)

MLX_PATH_L	= ./minilibx-linux/
MLX_NAME_L	= libmlx.a
MLX_L			= $(MLX_PATH_L)$(MLX_NAME_L)

all: $(MLX_L) $(NAME)   $(OBJ)

$(MLX_L):
	@echo "Making MiniLibX..."
<<<<<<< HEAD
	@make -sC  $(MLX_PATH)
	cp $(MLX) ./
=======
	@make -sC $(MLX_PATH_L)
	# cp $(MLX_L) ./
>>>>>>> cee797d503c50363f8ddcba168a0b09ee238d479

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	

$(NAME): $(OBJ)
	$(CC)   -o $(NAME) $(OBJ) $(LFLAGS)
clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)

fclean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH_L)
	rm -rf $(MLX_NAME_L)


re:     fclean all