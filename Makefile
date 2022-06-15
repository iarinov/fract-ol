# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 19:50:45 by annaiarinov       #+#    #+#              #
#    Updated: 2022/06/15 13:21:33 by aiarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = 	fractol
# MLX = 	minilibx/libmlx.a
# LIBFT = libft/libft.a
SRC = 	main.c fractol.c window.c utils.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

# %.o: %.c
$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx
	gcc $(OBJ) ./libft/libft.a -o fractol  $(FLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit


# $(NAME): $(MLX) $(LIBFT) $(OBJ)
# 	gcc $(FLAGS) $^ -o $@

# $(MLX):
# 	make --directory=./minilibx

# $(LIBFT):
# 	make --directory=./libft

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all




