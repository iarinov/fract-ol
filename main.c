/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:25 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/01 16:17:23 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "paint_mandelbrot.h"
#include "window.h"
/******BRIEF****\
 * NAME        : get_fractal_name
 * PARAM 	   : str name
 * DESCRIPTION : GET NAME FROM THREE TITLE (MAN, JULIA, SET)
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */

double	ft_atof(char *s)
{
	double	res;
	double	res2;
	int		len;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	res = (double)ft_atoi(&s[i]);
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '.')
		i++;
	res2 = (double)ft_atoi(&s[i]);
	len = ft_strlen(&s[i]);
	while (len-- > 0)
		res2 /= 10;
	return (res + (res2 * sign));
}

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

/******BRIEF****\
 * NAME        : get_fractal_name
 * PARAM 	   : str name
 * DESCRIPTION : GET NAME FROM THREE TITLE (MAN, JULIA, SET)
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */
// void paint_mandelbrot_fract()
// {
// }
/******BRIEF****\
 * NAME        : programm_center
 * PARAM 	   : NUMBER OF REQ FRACTAL
 * DESCRIPTION : ACCORDING TO NUM OF FRACTAL, call function for drawing
 * 				MAN === 1 | JULIA == 2 | SET == 3
 */
void programm_center(int num_of_fractal)
{

	// t_my_mlx mlx_main;
	// t_param param;
	t_core core;
	core.param.min_re = -2.0;
	core.param.max_re = 1.0;
	core.param.min_im = -1.2;
	core.param.zoom = 1;
	core.mlx_main.win_heigh = IMG_HEIGHT;
	core.mlx_main.win_width = IMG_WIDTH;
	core.mlx_main.mlx_ptr = mlx_init();
	core.mlx_main.mlx_win = mlx_new_window(core.mlx_main.mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "Hello world!");
	if (core.mlx_main.mlx_win != NULL)
	{
		core.mlx_main.mlx_img = mlx_new_image(core.mlx_main.mlx_img, IMG_WIDTH, IMG_HEIGHT);
		if (core.mlx_main.mlx_img != NULL)
		{
			// image->addr = mlx_get_data_addr(image->ptr_img,
			// 		&image->bpp, &image->line_len, &image->endian);
			// init(core.mlx_main.mlx_img);
			// get_set(core.mlx_main.mlx_img);
			mlx_key_hook(core.mlx_main.mlx_win, &handle_key, &core);
			mlx_mouse_hook(core.mlx_main.mlx_win, &mouse_move, &core);
			mlx_hook(core.mlx_main.mlx_win, 17, 0, &clean, &core);
			mlx_loop(core.mlx_main.mlx_ptr);
		}
	// mlx_put_image_to_window(core.mlx_main.mlx_ptr, core.mlx_main.mlx_win, core.mlx_main.mlx_img, 0, 0);
	// if (core.mlx_main.mlx_ptr != NULL && core.mlx_main.mlx_ptr != NULL)
	// {
	// 	mlx_key_hook(core.mlx_main.mlx_win, &handle_key, &core);
	// 	mlx_mouse_hook(core.mlx_main.mlx_win, &mouse_move, &core);
	// 	mlx_hook(core.mlx_main.mlx_win, 17, 0, &clean, &core);
	}
	if (num_of_fractal == 1)
		paint_mandelbrot(&core);
	// else if (num_of_fractal == 2)
	// paint_julia (mlx, mlx_win);
	// else if (num_of_fractal == 3)
	// paint_set(mlx, mlx_win);
	// mlx_loop(core.mlx_main.mlx_ptr); // to nut
	mlx_destroy_window(core.mlx_main.mlx_ptr, core.mlx_main.mlx_win);
	free(core.mlx_main.mlx_ptr);
}

int main(int argc, char **argv)
{
	programm_center(1);
	t_core *core;
	// if (argc == 1)
	// return (instruction());
	if (argc == 2)
	{
		programm_center(get_fractal_name(argv[1]));
		// else return (instruction());
	}
	if (argc == 4)
		{
			core->param.constant_re = ft_atof(argv[2]);
			core->param.constant_im = ft_atof(argv[3]);
		}
		else
		{
			core->param.constant_re = -0.4;
			core->param.constant_im = 0.6;
		}
	return (0);
}
