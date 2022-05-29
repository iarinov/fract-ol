/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:06:34 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/29 16:01:56 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
#include "window.h"

#include "./minilibx/mlx.h"

int handle_key (int keycode, t_my_mlx *mlx_main)
{
	if (keycode == 53 || keycode == 12)
		clean (mlx_main->mlx_win);
	return (0);
}

int clean (t_my_mlx *mlx_main)
{
	mlx_destroy_window(mlx_main->mlx_ptr, mlx_main->mlx_win);
	return (0);
}

void	mouse_move(int keycode, int x, int y, t_my_mlx *mlx_main)
{
	double zoom;
	t_param *param;
	if (keycode == 4 || keycode == 27 || keycode == 78)
		zoom = 1.1;
	else if (keycode == 5 || keycode == 24 || keycode == 69)
		zoom = 1.0 / 1.1;


	param->c_re = MIN_RE + x * image->coef_re;
	param->c_im = image->max_im - y * image->coef_im;



	image->max_re = image->c_re + (image->max_re - image->c_re) * image->zoom;
	image->min_re = image->c_re + (image->min_re - image->c_re) * image->zoom;


	image->max_im = image->c_im + (image->max_im - image->c_im) * image->zoom;
	image->min_im = image->c_im + (image->min_im - image->c_im) * image->zoom;


	image->coef_re = (image->max_re - image->min_re) / (IMG_WIDTH - 1);
	image->coef_im = (image->max_im - image->min_im) / (IMG_HEIGHT - 1);
}


int	handle_mouse(int keycode, int x, int y, t_my_mlx *mlx_main)
{
	x = IMG_WIDTH / 2;
	y = IMG_HEIGHT / 2;
	if (keycode == 4 || keycode == 5)
		mouse_move(keycode, IMG_WIDTH / 2, IMG_HEIGHT / 2, mlx_main);
	get_set(image);
	return (0);
}
