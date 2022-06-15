/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:25 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 16:20:57 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "utils.h"

void	instruction(void)
{
	write(1, "\n", 1);
	write(1, "-> Use: ./fractol [name] [num.num]\n", 35);
	write(1, "\n", 1);
	write(1, "[name] is a string.\n", 20);
	write(1, "[num.num] is a floating point number ('.' - delimeter).\n", 56);
	write(1, "\n", 1);
	write(1, "  - [Mandelbrot] for Mandelbrot set\n", 36);
	write(1, "  - [Julia] for Julia set\n", 26);
	write(1, "\n", 1);
	write(1, "For [Mandelbrot] NO additional parameters possible\n", 51);
	write(1, "For [Julia] either none OR 2 parameters possible.\n", 50);
	write(1, "\n", 1);
	write(1, "-> Example: ./fractol Mandelbrot\n", 33);
	write(1, "-> Example: ./fractol Julia −0.4 0.6\n", 39);
	write(1, "\n", 1);
	write(1, "Use arrows - + and mouse during the evaluation\n", 55);
}

int	get_fractal_name(char *name)
{
	if (ft_strncmp(name, "Mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(name, "Julia", 6) == 0)
		return (2);
	return (0);
}

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
	if (core->fractal_type == MANDELBROT)
	{
		core->param.min_re = -2.0;
		core->param.max_re = 1.0;
		core->param.min_im = -1.2;
		core->param.zoom = 1;
	}
	else if (core->fractal_type == JULIA)
	{
		core->param.min_re = -2.0;
		core->param.max_re = 2.0;
		core->param.min_im = -1.5;
		core->param.zoom = 1;
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
	paint_mandelbrot(core);
	mlx_loop(core->mlx_main.mlx_ptr);
	mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	free(core->mlx_main.mlx_ptr);
}

int	main(int argc, char **argv)
{
	int		type_of_fractal;
	t_core	core;

	type_of_fractal = get_fractal_name(argv[1]);
	if (argc == 1 || (type_of_fractal != MANDELBROT
			&& type_of_fractal != JULIA))
		instruction();
	else if (argc >= 2)
	{
		if (type_of_fractal == JULIA && argc == 4)
		{
			if ((ft_atof(argv[2]) > DBL_MAX || ft_atof(argv[2]) < (-DBL_MAX))
				|| (ft_atof(argv[3]) < (-DBL_MAX)
					|| ft_atof(argv[3]) > DBL_MAX))
				instruction ();
			else if (argc == 2)
			{
				core.param.constant_re = -0.8;
				core.param.constant_im = 0.156;
				core.fractal_type = JULIA;
				programm_center(&core);
				return (0);
			}
			else
			{
				core.param.constant_re = ft_atof(argv[2]);
				core.param.constant_im = ft_atof(argv[3]);
				core.fractal_type = JULIA;
				programm_center(&core);
				return (0);
			}
			return (0);
		}
		else if (type_of_fractal == MANDELBROT)
		{
			core.fractal_type = MANDELBROT;
			programm_center(&core);
			return (0);
		}
	}
	return (0);
}
