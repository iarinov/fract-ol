/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:06:34 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/01 15:19:16 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
#include "window.h"

#include "./minilibx/mlx.h"
#include "paint_mandelbrot.h"

int	color(t_core *core, int n)
{
	int	pix_color;

	if (core->param.color == 1)
		pix_color = get_classic(n);
	if (core->param.color == 2)
		pix_color = get_classic2(n);
	return (pix_color);
}

void window_init(t_core *core)
{
	clean(core);
	// core->mlx_main.mlx_ptr = mlx_init();
	// core->mlx_main.mlx_win = mlx_new_window(core->mlx_main.mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "Hello world!");
	//  if (core->mlx_main.mlx_ptr != NULL && core->mlx_main.mlx_ptr != NULL)
	//  {
	//  	mlx_key_hook(core->mlx_main.mlx_win, &handle_key, &core);
	//  	mlx_mouse_hook(core->mlx_main.mlx_win, &mouse_move, &core);
	//  }
}
int handle_key(int keycode, t_core *core)
{
	if (keycode == 53 || keycode == 12)
		mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	else if(keycode == 123)//left
	{
		core->param.horis -= 0.1;
	}
	else if(keycode == 124)//right
	{
		core->param.horis += 0.1;
	}
	else if (keycode == 125)//down
	{
		core->param.vert += 0.1;
	}
	else if (keycode == 126)//up
	{
		core->param.vert -= 0.1;
	}
	else if (keycode == 9)
	{
		core->param.color = 1;
	}
	else if (keycode == 11)
		core->param.color = 2;
	clean (core);
	// mlx_clear_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	paint_mandelbrot (core);
	// paint_julia (core);
	return (0);
}

int clean(t_core *core)
{
	mlx_clear_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	// mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	return (0);
}

int mouse_move(int keycode, int x, int y, t_core *core)
{
	x = 0;
	y = 0;
	if (keycode == 4 || keycode == 27 || keycode == 78)
	{
		core->param.zoom += 0.1;
	}
	else if (keycode == 5 || keycode == 24 || keycode == 69)
	{
		core->param.zoom -= 0.1;
	}
	if (core->param.zoom == 0)
		core->param.zoom = 1;
	// else
	// 	return (0);
	// window_init(core);
	// mlx_clear_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	paint_mandelbrot(core);
	// paint_julia (core);
	return (0);
}

