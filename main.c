/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:25 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 11:03:39 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "utils.h"
#include "input_control.h"
#include "fractol.h"

static t_my_mlx	init_mlx(void)
{
	t_my_mlx	mlx_main;

	mlx_main.win_heigh = IMG_HEIGHT;
	mlx_main.win_width = IMG_WIDTH;
	mlx_main.mlx_ptr = mlx_init();
	mlx_main.mlx_win = mlx_new_window(mlx_main.mlx_ptr, IMG_HEIGHT,
			IMG_WIDTH, "Fract'ol");
	mlx_main.mlx_img = mlx_new_image(mlx_main.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	return (mlx_main);
}

static void	init_param(t_core *core)
{
	core->param.min_re = -2.0;
	core->param.zoom = 1;
	if (core->fractal_type == MANDELBROT)
	{
		core->param.max_re = 1.0;
		core->param.min_im = -1.2;
	}
	else if (core->fractal_type == JULIA)
	{
		core->param.max_re = 2.0;
		core->param.min_im = -1.5;
	}
	core->mlx_main.mlx_data_addr = mlx_get_data_addr(core->mlx_main.mlx_img,
			&(core->param.bpp), &(core->param.line_len),
			&(core->param.endian));
}

static void	init_event_hook(t_core *core)
{
	mlx_key_hook((core->mlx_main.mlx_win), &handle_key, core);
	mlx_mouse_hook((core->mlx_main.mlx_win), &mouse_move, core);
	mlx_hook((core->mlx_main.mlx_win), 17, 0, &destroy, core);
}

void	programm_center(t_core *core)
{
	core->mlx_main = init_mlx();
	if (core->mlx_main.mlx_ptr != NULL && core->mlx_main.mlx_ptr != NULL)
	{
		init_param(core);
		init_event_hook(core);
	}
	paint_fractol(core);
	mlx_loop(core->mlx_main.mlx_ptr);
	mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	free(core->mlx_main.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (is_valid_argument(argc, argv))
	{
		extract_param(argc, argv, &core);
		programm_center(&core);
	}
	else
		write (1, INSTRUCTIONS, ft_strlen(INSTRUCTIONS));
	return (0);
}
