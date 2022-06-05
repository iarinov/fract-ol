/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:25 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/04 19:51:10 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "paint_mandelbrot.h"
#include "window.h"
#include "utils.h"

/******BRIEF****\
 * NAME        : get_fractal_name
 * PARAM 	   : str name
 * DESCRIPTION : GET NAME FROM THREE TITLE (MAN, JULIA, SET)
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */
int get_fractal_name(char *name)
{
	if (ft_strncmp(name, "Mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(name, "Julia", 6) == 0)
		return (2);
	return (0);
}
/******BRIEF****\
 * NAME        : get_fractal_name
 * PARAM 	   : str name
 * DESCRIPTION : GET NAME FROM THREE TITLE (MAN, JULIA, SET)
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */

static t_my_mlx init_mlx(void)
{
	t_my_mlx mlx_main;
	mlx_main.win_heigh = IMG_HEIGHT;
	mlx_main.win_width = IMG_WIDTH;
	mlx_main.mlx_ptr = mlx_init();
	mlx_main.mlx_win = mlx_new_window(mlx_main.mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "Fract'ol");
	mlx_main.mlx_img = mlx_new_image(mlx_main.mlx_img, IMG_WIDTH, IMG_HEIGHT);
	return (mlx_main);
}
/******BRIEF****
 * NAME        : programm_center
 * PARAM 	   : NUMBER OF REQ FRACTAL
 * DESCRIPTION : ACCORDING TO NUM OF FRACTAL, call function for drawing
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */
static void init_param(t_core *core)
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
													 &(core->param.bpp), &(core->param.line_len), &(core->param.endian));
}

/******BRIEF****\
 * NAME        : programm_center
 * PARAM 	   : NUMBER OF REQ FRACTAL
 * DESCRIPTION : ACCORDING TO NUM OF FRACTAL, call function for drawing
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */

static void init_event_hook(t_core *core)
{
	mlx_key_hook((core->mlx_main.mlx_win), &handle_key, core);
	mlx_mouse_hook((core->mlx_main.mlx_win), &mouse_move, core);
	mlx_hook((core->mlx_main.mlx_win), 17, 0, &destroy, core);
}

/******BRIEF****\
 * NAME        : programm_center
 * PARAM 	   : NUMBER OF REQ FRACTAL
 * DESCRIPTION : ACCORDING TO NUM OF FRACTAL, call function for drawing
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */
void programm_center(t_core *core)
{
	core->mlx_main = init_mlx();

	if (core->mlx_main.mlx_ptr != NULL && core->mlx_main.mlx_ptr != NULL)
	{
		init_param(core);
		init_event_hook(core);
	}
	paint_mandelbrot(core);

	// else if (num_of_fractal == 2)
	// paint_julia (mlx, mlx_win);
	// else if (num_of_fractal == 3)
	// paint_set(mlx, mlx_win);

	mlx_loop(core->mlx_main.mlx_ptr); // to nut
	mlx_destroy_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win);
	free(core->mlx_main.mlx_ptr);
}

int main(int argc, char **argv)
{
	int type_of_fractal;
	t_core core;
	// programm_center(1);

	// if (argc == 1)
	// 	return (instruction());
	if (argc > 1)
	{
		type_of_fractal = get_fractal_name(argv[1]);
		if (type_of_fractal == JULIA && argc == 4)
		{
			core.param.constant_re = ft_atof(argv[2]);
			core.param.constant_im = ft_atof(argv[3]);
			core.fractal_type = JULIA;
			programm_center(&core);
			return (0);
		}
		else if (type_of_fractal == MANDELBROT)
		{
			core.fractal_type = MANDELBROT;
			programm_center(&core);
			return (0);
		}
	}
	printf("instruction");

	return (0);
}
