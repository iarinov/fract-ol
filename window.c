/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:06:34 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 15:04:36 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "fractol.h"

int	handle_key(int keycode, t_core *core)
{
	if (keycode == 53 || keycode == 12)
		destroy(core);
	if (keycode == 123)
		core->param.horis -= 0.1;
	else if (keycode == 124)
		core->param.horis += 0.1;
	else if (keycode == 125)
		core->param.vert += 0.1;
	else if (keycode == 126)
		core->param.vert -= 0.1;
	else if (keycode == 27 || keycode == 78)
		core->param.zoom *= 0.8;
	else if (keycode == 24 || keycode == 69)
		core->param.zoom *= 1.2;
	else
		return (0);
	clean(core);
	paint_fractol(core);
	return (0);
}

int	destroy(t_core *core)
{
	clean(core);
	mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	exit(0);
	return (0);
}

int	clean(t_core *core)
{
	mlx_clear_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	return (0);
}

int	mouse_move(int keycode, int x, int y, t_core *core)
{
	x = 0;
	y = 0;
	if (keycode == 4)
	{
		core->param.zoom *= 0.8;
	}
	else if (keycode == 5)
	{
		core->param.zoom *= 1.2;
	}
	else
		return (0);
	if (core->param.zoom == 0)
		core->param.zoom = 1;
	clean(core);
	paint_fractol(core);
	return (0);
}
