# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:50:53 by mstrauss          #+#    #+#              #
#    Updated: 2024/03/22 17:30:52 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS= $(addprefix $(SRC_DIR)/, main.c)

OBJECTS = $(SRCS:.c=.o)
# OBJECTS := $(OBJECTS)

CC = gcc

CFLAGS			= -Wall -Werror -Wextra -lm
DEBUG_FLAGS 	= -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
VALGRIND_FLAGS 	= -g

LIBFT_DIR = ./libft
MLX_DIR = 	./mlx
BUILD_DIR = ./build
SRC_DIR = ./src

LIBFT       = $(LIBFT_DIR)/libft.a
MLX 		= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm


all: mlx $(LIBFT) ${NAME}

debug: CFLAGS += $(DEBUG_FLAGS)
debug: 
	make -C $(LIBFT_DIR) debug
	make clean
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} $(LIBFT) $(MLX)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFT_DBG):
	make -C $(LIBFT_DIR) debug

mlx:
	cmake ./mlx/ -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}
	rm -rf $(MLX_DIR)/build
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

.PHONY: mlx clean fclean all debug