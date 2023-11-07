# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 12:01:22 by jperinch          #+#    #+#              #
#    Updated: 2023/11/07 10:39:07 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cube3d

SRC = 	cube3d.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -fsanitize=address -g3##-Wall -Wextra -Werror 
CC = gcc

MLX_PATH	= ./mlx/
MLX_NAME	= libmlx.dylib
MLX			= $(MLX_PATH)$(MLX_NAME)

all: $(MLX) $(NAME)   $(OBJ)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC  $(MLX_PATH)
	cp $(MLX) ./

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(PRINTF) $(MLX) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH)

fclean:
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	@make clean -sC $(MLX_PATH)
	rm -rf $(MLX_NAME)


re:     fclean all