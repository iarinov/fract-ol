# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 19:50:45 by annaiarinov       #+#    #+#              #
#    Updated: 2022/06/15 22:34:06 by annaiarinov      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC = main.c fractol.c window.c utils.c input_control.c color.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx
	gcc $(OBJ) ./libft/libft.a -o fractol  $(FLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all




