/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:37:36 by aiarinov          #+#    #+#             */
/*   Updated: 2022/05/16 16:23:30 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		color;
	int x;
	int y;

	mlx = mlx_init();
	x = 100;
	y = 100;
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	while (x < 250 && y < 250)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, color);
		x++;
		y++;
	}
	while (x < 400 && y > 100)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, color);
		x++;
		y--;
	}
	while (x > 100)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, color);
		x--;
	}
	// while (y < 350)
	// {
	// 	mlx_pixel_put(mlx, mlx_win, x, y, color);
	// 	y++;
	// }
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

