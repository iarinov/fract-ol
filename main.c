/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:25 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/29 20:08:39 by annaiarinov      ###   ########.fr       */
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
int get_fractal_name(char *name)
{
	if (ft_strncmp(name, "Mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(name, "Julia", 6) == 0)
		return (2);
	else if (ft_strncmp(name, "Set", 4) == 0)
		return (3);

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
	t_my_mlx mlx_main;
	t_param param;
	mlx_main.mlx_ptr = mlx_init();
	mlx_main.mlx_win = mlx_new_window(mlx_main.mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "Hello world!");
	if (mlx_main.mlx_ptr != NULL && mlx_main.mlx_ptr != NULL)
	{
		mlx_key_hook(mlx_main.mlx_win, &handle_key, &mlx_main);
		mlx_mouse_hook(mlx_main.mlx_win, &mlx_mouse_move, &param);
	}
	if (num_of_fractal == 1)
		paint_mandelbrot(&mlx_main, &param);

	// else if (num_of_fractal == 2)
	// paint_julia (mlx, mlx_win);
	// else if (num_of_fractal == 3)
	// paint_set(mlx, mlx_win);

	mlx_loop(mlx_main.mlx_ptr); // to nut
	mlx_destroy_window(mlx_main.mlx_ptr, mlx_main.mlx_win);
	free(mlx_main.mlx_ptr);
}

int main(int argc, char **argv)
{
	programm_center(1);

	// if (argc == 1)
	// return (instruction());
	if (argc == 2)
	{
		printf("%s\n", argv[1]);

		// programm_center(get_fractal_name(argv[1]));
		// else return (instruction());
	}
	return (0);
}
