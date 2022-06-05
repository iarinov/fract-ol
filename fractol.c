/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:28:15 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/05 18:05:40 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "window.h"

static void fractol_loop(t_core *core, bool *p_is_inside, unsigned int *p_fractal_iter);

static void set_color(const t_core *core, const unsigned int fractal_iter, const bool is_inside);

int get_classic(int n)
{
	int color[16];
	if (n > 15 || n < 0)
	{
		return 0;
	}
	color[0] = 0x00e8eaf6;
	color[1] = 0x00c5cae9;
	color[2] = 0x009fa8da;
	color[3] = 0x007986cb;
	color[4] = 0x005c6bc0;
	color[5] = 0x003f51b5;
	color[6] = 0x00311b92;
	color[7] = 0x004527a0;
	color[8] = 0x00512da8;
	color[9] = 0x005e35b1;
	color[10] = 0x00673ab7;
	color[11] = 0x007e57c2;
	color[12] = 0x009575cd;
	color[13] = 0x00b39ddb;
	color[14] = 0x00d1c4e9;
	color[15] = 0x00ede7f6;
	return (color[n]);
}

void put_color(const t_core *core, int color)
{
	char *pos;
	pos = core->mlx_main.mlx_data_addr + (core->param.y * core->param.line_len + core->param.x * (core->param.bpp / 8));
	*(int *)pos = color;
}

static void init_mandel_param(t_core *core)
{
	core->param.max_im = core->param.min_im + (core->param.max_re - core->param.min_re) * core->mlx_main.win_heigh / core->mlx_main.win_width; // imageHeight/ImageWidth
	core->param.re_factor = (core->param.max_re - core->param.min_re) / (core->mlx_main.win_width - 1);										   // ImageWidth because real is x
	core->param.im_factor = (core->param.max_im - core->param.min_im) / (core->mlx_main.win_heigh - 1);										   // ImageHeight because imaginary is y
}

void paint_mandelbrot(t_core *core)
{
	unsigned int n;
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
			fractol_loop(core, &is_inside, &n);
			set_color(core, n, is_inside);
			core->param.x++;
		}
		core->param.y++;
	}
	mlx_put_image_to_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win, core->mlx_main.mlx_img,
							0, 0);
}

static void fractol_loop(t_core *core, bool *p_is_inside, unsigned int *p_fractal_iter)
{
	unsigned int n = 0;
	bool is_inside = true;
	double Z_re2;
	double Z_im2;
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
	*p_is_inside = is_inside;
	*p_fractal_iter = n;
}

static void set_color(const t_core *core, const unsigned int fractal_iter, const bool is_inside)
{
	int color = 0xfffafa;
	double Z_re2;
	double Z_im2;

	Z_re2 = core->param.z_re * core->param.z_re;
	Z_im2 = core->param.z_im * core->param.z_im;
	if (is_inside)
	{
		color = ceil(sqrt(Z_im2 + Z_re2) * 8.0);
	}
	else
	{
		color = (int)(fractal_iter) %16;
		// color = (fractal_iter + 1 - log(log2(fabs(Z_re2 + Z_im2))));
	}
	color = get_classic(color);
	put_color(core, color);
}
