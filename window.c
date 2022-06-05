/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:06:34 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/04 19:50:43 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include "./minilibx/mlx.h"
#include "paint_mandelbrot.h"
#include <stdlib.h>

#define ESC_PRESS(x) (x == 53 || x == 12)
#define LEFT_PRESS(x) (x == 123)
#define RIGHT_PRESS(x) (x == 124)
#define DOWN_PRESS(x) (x == 125)
#define UP_PRESS(x) (x == 126)

int handle_key(int keycode, t_core *core)
{
	if (ESC_PRESS(keycode))
		destroy(core);
	if (LEFT_PRESS(keycode))
	{
		core->param.horis -= 0.1;
	}
	else if (RIGHT_PRESS(keycode))
	{
		core->param.horis += 0.1;
	}
	else if (DOWN_PRESS(keycode))
	{
		core->param.vert += 0.1;
	}
	else if (UP_PRESS(keycode))
	{
		core->param.vert -= 0.1;
	}
	else
	{
		return(0);
	}
	clean(core);
	paint_mandelbrot(core);
	return (0);
}

int destroy(t_core *core)
{
	clean(core);
	mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	exit(0);
	return (0);
}
int clean(t_core *core)
{
	mlx_clear_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	return (0);
}

int mouse_move(int keycode, int x, int y, t_core *core)
{

	x = 0;
	y = 0;
	if (keycode == 4 || keycode == 27 || keycode == 78)
	{
		core->param.zoom += 0.1;
		// core->mlx_main.win_heigh *= zoom;
	}
	else if (keycode == 5 || keycode == 24 || keycode == 69)
	{
		core->param.zoom -= 0.1;
		// core->mlx_main.win_heigh *= zoom;
	}
	else
		return (0);
	if (core->param.zoom == 0)
		core->param.zoom = 1;
	clean(core);
	paint_mandelbrot(core);
	return (0);
}
