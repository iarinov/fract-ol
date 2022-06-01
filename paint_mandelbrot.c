/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:28:15 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/01 15:44:45 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_code.h"
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
	color[0] = 0x00e8eaf6;
	color[1] = 0x00c5cae9;
	color[2] = 0x009fa8da;
	color[3] = 0x007986cb;
	color[4] = 0x005c6bc0;
	color[5] = 0x003f51b5;
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

int get_classic2(int n)
{
	t_core *core;
	core->param.color[16];
	if(n > 15 || n < 0)
	{
		return 0;
	}
	core->param.color[0] = 0x00ede7f6;
	core->param.color[1] = 0x00d1c4e9;
	core->param.color[2] = 0x00b39ddb;
	core->param.color[3] = 0x009575cd;
	core->param.color[4] = 0x007e57c2;
	core->param.color[5] = 0x00673ab7;
	core->param.color[6] = 0x005e35b1;
	core->param.color[7] = 0x00512da8;
	core->param.color[8] = 0x004527a0;
	core->param.color[9] = 0x00311b92;
	core->param.color[10] = 0x00b388ff;
	core->param.color[11] = 0x007c4dff;
	core->param.color[12] = 0x00651fff;
	core->param.color[13] = 0x006200ea;
	core->param.color[14] = 0x00f3e5f5;
	core->param.color[15] = 0x00e1bee7;
	return (core->param.color[n]);
}
static void init_mandel_param(t_core *core)
{
	core->param.max_im = core->param.min_im + (core->param.max_re - core->param.min_re) * core->mlx_main.win_heigh / core->mlx_main.win_width;
	core->param.re_factor = (core->param.max_re - core->param.min_re) / (core->mlx_main.win_width - 1);
	core->param.im_factor = (core->param.max_im - core->param.min_im) / (core->mlx_main.win_heigh - 1);
}

void paint_mandelbrot(t_core *core)
{
	// core->param.color = 0xfffafa;
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
				core->param.z_im = 2 * core->param.z_re * core->param.z_im + core->param.c_im;
				core->param.z_re = Z_re2 - Z_im2 + core->param.c_re;
				n++;
			}
			if (is_inside)
			{
				// core->param.color = ceil(sqrt(Z_im2 + Z_re2) * 8.0);
			}
			else
			{

				// color = n + 1 - log(log2(fabs(Z_re2 + Z_im2)));
				core->param.color = n % 16;
			}
			// color = get_classic(color);
			mlx_pixel_put(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win, core->param.x, core->param.y, core->param.color);
			core->param.x++;
		}
		core->param.y++;
	}
}


