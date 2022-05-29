/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:28:15 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/29 13:18:09 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ITER (40)
#define MIN_RE (-2.0)
#define MAX_RE (1.0)
#define MIN_IM (-1.2)
#define IMG_HEIGHT (400)
#define IMG_WIDTH (400)
#define SQR (x) (x * x)

typedef struct
{
	double c_re;
	double c_im;
	double z_re;
	double z_im;
}t_param;


void paint_mandelbrot(t_my_mlx *main_mlx)
{
	int color = RED;
	t_param param;
	unsigned int y;
	unsigned int x;
	unsigned int n;
	bool is_inside;
	x = 0;
	y = 0;
	n = 0;
	double MaxIm = MIN_IM + (MAX_RE - MIN_RE) * IMG_HEIGHT / IMG_WIDTH; // imageHeight/ImageWidth
	double Re_factor = (MAX_RE - MIN_RE) / (IMG_WIDTH - 1);		// ImageWidth because real is x
	double Im_factor = (MaxIm - MIN_IM) / (IMG_HEIGHT - 1);		// ImageHeight because imaginary is y

	while (y < IMG_HEIGHT)
	{
		param.c_im = MaxIm - y * Im_factor;
		x = 0;
		while (x < IMG_WIDTH)
		{
			param.c_re = MIN_RE + x * Re_factor;
			param.z_re = param.c_re;
			param.z_im = param.c_im;
			is_inside = true;
			while (n < MAX_ITER)
			{
				if (SQR(param.z_re) + SQR(param.z_im) > 4)
				{
					is_inside = false;
					break;
				}
				param.z_im = 2 * param.z_re * param.z_im + param.c_im;
				param.z_re = SQR(param.z_re) - SQR(param.z_im) + param.c_re;
				n++;
			}
			x++;
		}
		y++;
	}
	for (unsigned int y = 0; y < 400; ++y) // till we reach the end of the image height
	{
		double c_im = MaxIm - y * Im_factor;   // complex value for imaginary, conctant c
		for (unsigned int x = 0; x < 400; ++x) // till we reach the end of the image bright
		{
			double c_re = MinRe + x * Re_factor; // compex value for real, constant c
			double Z_re = c_re;
			double Z_im = c_im;
			bool isInside = true;
			double Z_re2;
			double Z_im2;
			for (n = 0; n < MaxIterations; ++n)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4) // absolut value of Z
				{
					isInside = false;
					break;
				}
				Z_im = 2 * Z_re * Z_im + c_im; // become that from (x + yi)^2 = x^2 + 2xyi + yi^2 -> 2xy
				Z_re = Z_re2 - Z_im2 + c_re;   // x^2 - y^2
			}
			if (Z_re2 + Z_im2 > 3.0 && Z_re2 + Z_im2 < 4.5)
			{
				color = RED;
			}
			else if (Z_re2 + Z_im2 > 4.5 && Z_re2 + Z_im2 < 5.5)
			{
				color = PURPLE;
			}
			else if (Z_re2 + Z_im2 > 5.5 && Z_re2 + Z_im2 < 6.5)
			{
				color = ORANGE;
			}
			else
			{
				color = LIGHT_GREEN;
			}
			mlx_pixel_put(main_mlx->mlx_ptr, main_mlx->mlx_win, x, y, color);


			// if(isInside)
			//  {
			// 	mlx_pixel_put(mlx, mlx_win, x, y, color);
			//  }
			//  else
			//  {
			// 	mlx_pixel_put(mlx, mlx_win, x, y, BLUE);
			//  }
		}
	}
}
