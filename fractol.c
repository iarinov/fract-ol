/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:52:45 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/15 20:03:59 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		color;
	int x;

	mlx = mlx_init();
	x = 0;
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	while (x < 500)
	{
		mlx_pixel_put(mlx, mlx_win, x, x, color);
		x++;
	}
	mlx_pixel_put(mlx, mlx_win, 250, 250, color);
	mlx_loop(mlx);

}
