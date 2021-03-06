/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:15:10 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 15:04:05 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define MAX_ITER 50
# define IMG_HEIGHT 600
# define IMG_WIDTH 600
# define JULIA 2
# define MANDELBROT 1

# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <float.h>

typedef struct my_mlx
{
	void			*mlx_win;
	void			*mlx_ptr;
	void			*mlx_img;
	char			*mlx_data_addr;
	unsigned int	win_width;
	unsigned int	win_heigh;

}	t_my_mlx;

typedef struct param
{
	unsigned int	x;
	unsigned int	y;
	double			zoom;
	double			horis;
	double			vert;
	double			max_im;
	double			max_re;
	double			min_im;
	double			min_re;
	double			re_factor;
	double			im_factor;
	double			c_re;
	double			c_im;
	double			constant_re;
	double			constant_im;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
	int				bpp;
	int				line_len;
	int				endian;
	bool			is_inside;

}	t_param;

typedef struct core
{
	t_my_mlx	mlx_main;
	t_param		param;
	int			fractal_type;
}	t_core;

int		handle_key(int keycode, t_core *core);
int		clean(t_core *core);
int		mouse_move(int keycode, int x, int y, t_core *core);
int		destroy(t_core *core);

#endif
