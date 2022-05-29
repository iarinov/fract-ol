# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 19:50:45 by annaiarinov       #+#    #+#              #
#    Updated: 2022/05/28 20:22:44 by annaiarinov      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

LIBM = minilibx/

LIBFT = libft/

LIBMS = minilibx/

SRCS = main.c paint_mandelbrot.c window.c 

all: $(NAME)

$(NAME):
		make -C $(LIBM)
		make -C $(LIBFT)
		gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(LIBMS) -L $(LIBMS) \
		-lmlx -L $(LIBFT) -lft -framework OpenGL -framework AppKit

clean:
		make -C $(LIBM) clean
		make -C $(LIBFT) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(LIBFT) fclean

re: fclean all
		make -C $(LIBM) re
		make -C $(LIBFT) re



