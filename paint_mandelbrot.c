/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:28:15 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/04 19:53:46 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "window.h"


int get_classic(int n)
{
	int color[16];
	if(n > 15 || n < 0)
	{
		return 0;
	}
	color[0] = 0x00421E48;
	color[1] = 0x0019071A;
	color[2] = 0x0009012F;
	color[3] = 0x00040449;
	color[4] = 0x00000764;
	color[5] = 0x000C2C8A;
	color[6] = 0x001852B1;
	color[7] = 0x00397DD1;
	color[8] = 0x0086B5E5;
	color[9] = 0x00D3ECF8;
	color[10] = 0x00F1E9BF;
	color[11] = 0x00F8C95F;
	color[12] = 0x00FFAA00;
	color[13] = 0x00CC8000;
	color[14] = 0x00995700;
	color[15] = 0x006A3403;
	return (color[n]);
}

void put_color(t_core *core, int color)
{
	char *pos;
	pos = core->mlx_main.mlx_data_addr + (core->param.y * core->param.line_len + core->param.x * (core->param.bpp / 8));
	*(int *)pos = color;
}

static void init_mandel_param(t_core *core)
{
	core->param.max_im = core->param.min_im + (core->param.max_re - core->param.min_re) * core->mlx_main.win_heigh / core->mlx_main.win_width; // imageHeight/ImageWidth
	core->param.re_factor = (core->param.max_re - core->param.min_re) / (core->mlx_main.win_width - 1);					  // ImageWidth because real is x
	core->param.im_factor = (core->param.max_im - core->param.min_im) / (core->mlx_main.win_heigh - 1);					  // ImageHeight because imaginary is y
}

void paint_mandelbrot(t_core *core)
{
	int color = 0xfffafa;
	unsigned int n;
	double Z_re2;
	double Z_im2;
	bool is_inside;
	core->param.x = 0;
	core->param.y = 0;
	n = 0;
	init_mandel_param(core);
	while (core->param.y < IMG_HEIGHT)
	{
		core->param.c_im = ((core->param.max_im - core->param.y * core->param.im_factor) / core->param.zoom) + core->param.vert;
		core->param.x = 0;
		while (core->param.x < IMG_WIDTH)
		{
			core->param.c_re = (core->param.min_re + core->param.x * core->param.re_factor) / core->param.zoom + core->param.horis;
			core->param.z_re = core->param.c_re;
			core->param.z_im = core->param.c_im;
			is_inside = true;
			n = 0;
			while (n < MAX_ITER)
			{
				Z_re2 = core->param.z_re * core->param.z_re;
				Z_im2 = core->param.z_im * core->param.z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					is_inside = false;
					break;
				}
				if (core->fractal_type == MANDELBROT)
				{
					core->param.z_im = 2 * core->param.z_re * core->param.z_im + core->param.c_im;
					core->param.z_re = Z_re2 - Z_im2 + core->param.c_re;
				}
				else if (core->fractal_type == JULIA)
				{
					core->param.z_im = 2 * core->param.z_re * core->param.z_im + core->param.constant_im;
					core->param.z_re = Z_re2 - Z_im2 + core->param.constant_re;
				}
				n++;
			}
			// if (n < MAX_ITER && n > 0)
			// 	color = (n + 1 - log(log2(fabs(Z_re2 + Z_im2))));
			// else
			// 	color = 0;
			if (is_inside)
			{
				color = (int)(n) %(16);
				//color = ceil(sqrt(Z_im2 + Z_re2) * 8.0);
				//color = (n + 1 - log(log2(fabs(Z_re2 + Z_im2))));
			}
			else
			{
				//color = (int)(n) %754;
				color = (n + 1 - log(log2(fabs(Z_re2 + Z_im2))));
			}
			color = get_classic(color);
			put_color(core, color);
			core->param.x++;
		}
		core->param.y++;
	}
	mlx_put_image_to_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win, core->mlx_main.mlx_img,
				0, 0);
}
