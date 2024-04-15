# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:50:53 by mstrauss          #+#    #+#              #
#    Updated: 2024/04/14 18:14:26 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BIN_DIR)/fractol

SRCS= $(addprefix $(SRC_DIR)/, main.c julia_math.c mandelbrot_math.c utils.c hooks.c colors.c)

OBJECTS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = cc

CFLAGS			= -Wall -Werror -Wextra -Wunreachable-code -Ofast -ffast-math -march=native -mtune=native -funroll-loops #-lm
DEBUG_FLAGS 	= -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
VALGRIND_FLAGS 	= -g

LIBFT_DIR 	=	./libft
MLX_DIR 	=	./mlx
BUILD_DIR 	=	./build
SRC_DIR 	=	./src
BIN_DIR 	=	./bin

LIBFT       =	$(BIN_DIR)/libft.a
MLX 		=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops

all: mlx $(LIBFT) ${NAME}

debug: CFLAGS += $(DEBUG_FLAGS)
debug: mlx $(OBJECTS)
	make -C $(LIBFT_DIR) debug
# make clean
	mkdir -p $(BIN_DIR)
	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) $(LIBFT) $(MLX)

${NAME}: $(OBJECTS)
	mkdir -p $(BIN_DIR)
	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) $(LIBFT) $(MLX)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(LIBFT_DBG):
	make -C $(LIBFT_DIR) debug

re: fclean all

mlx:
	cmake ./mlx/ -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)
	rm -rf $(MLX_DIR)/build
    
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

.PHONY: mlx clean fclean all debug re