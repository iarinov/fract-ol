# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 19:50:45 by annaiarinov       #+#    #+#              #
#    Updated: 2022/06/04 14:47:58 by annaiarinov      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror ./libft/libft.a -L ./minilibx -lmlx -framework OpenGL -framework AppKit
NAME = 	fractol
MLX = 	minilibx/libmlx.a
LIBFT = libft/libft.a
SRC = 	main.c paint_mandelbrot.c window.c utils.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -D BUFFER_SIZE=100 $^ -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $^ -o $@

$(MLX):
	make --directory=./minilibx

$(LIBFT):
	make --directory=./libft

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all




