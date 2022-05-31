/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:06:34 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/31 21:34:05 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
#include "window.h"

#include "./minilibx/mlx.h"
#include "paint_mandelbrot.h"

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
	clean (core);
	paint_mandelbrot (core);
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
	// keycode = 3;
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
	if (core->param.zoom == 0)
		core->param.zoom = 1;
	// else
	// 	return (0);


	window_init(core);

	paint_mandelbrot(core);

	return (0);
}

// int	handle_mouse(int keycode, int x, int y, t_my_mlx *mlx_main)
// {
// 	x = IMG_WIDTH / 2;
// 	y = IMG_HEIGHT / 2;
// 	if (keycode == 4 || keycode == 5)
// 		mouse_move(keycode, IMG_WIDTH / 2, IMG_HEIGHT / 2, mlx_main);
// 	get_set(image);
// 	return (0);
// }
