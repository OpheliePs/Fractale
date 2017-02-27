# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 00:57:13 by opettex-          #+#    #+#              #
#    Updated: 2016/05/19 18:32:45 by opettex-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =   src/main.c \
		src/fractol.c \
		src/key_hook.c \
		src/mandelbrot.c \
	   	src/julia.c \
		src/burning.c\
		src/celtique.c\
		src/mouse_hook.c

INC = -I ./include -I ./minilibx_macos

LIB = libft/libft.a
LIB_PATH = libft/

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

MLX_FLAG = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC) $(MLX_FLAG)
	@echo "fractol created"

%.o: %.c
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

.PHONY: clean fclean re all

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)
	@echo "fractol cleaned"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@echo "fractol deleted"

re: fclean all
