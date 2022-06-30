/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:28:15 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 14:56:58 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "color.h"

static void	fractol_loop(t_core *core, bool *p_is_inside,
				unsigned int *p_fractal_iter);

static void	init_mandel_param(t_core *core)
{
	t_param	*p;

	p = &core->param;
	p->max_im = p->min_im + (p->max_re - p->min_re) * core->mlx_main.win_heigh
		/ core->mlx_main.win_width;
	p->re_factor = (p->max_re - p->min_re) / (core->mlx_main.win_width - 1);
	p->im_factor = (p->max_im - p->min_im) / (core->mlx_main.win_heigh - 1);
}

void	paint_fractol(t_core *core)
{
	unsigned int	n;
	t_param			*p;

	p = &core->param;
	p->y = 0;
	n = 0;
	init_mandel_param(core);
	while (p->y < IMG_HEIGHT)
	{
		p->c_im = (p->max_im - p->y * p->im_factor) / p->zoom + p->vert;
		p->x = 0;
		while (p->x < IMG_WIDTH)
		{
			p->c_re = (p->min_re + p->x * p->re_factor) / p->zoom + p->horis;
			p->z_re = p->c_re;
			p->z_im = p->c_im;
			p->is_inside = true;
			fractol_loop(core, &p->is_inside, &n);
			set_color(core, n, p->is_inside);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(core->mlx_main.mlx_ptr, core->mlx_main.mlx_win,
		core->mlx_main.mlx_img, 0, 0);
}

static void	count_zim_zre(t_param *p, int fractal_type)
{
	if (fractal_type == MANDELBROT)
	{
		p->z_im = 2 * p->z_re * p->z_im + p->c_im;
		p->z_re = p->z_re2 - p->z_im2 + p->c_re;
	}
	else if (fractal_type == JULIA)
	{
		p->z_im = 2 * p->z_re * p->z_im + p->constant_im;
		p->z_re = p->z_re2 - p->z_im2 + p->constant_re;
	}
}

static void	fractol_loop(t_core *core, bool *p_is_inside,
						unsigned int *p_fractal_iter)
{
	unsigned int	n;
	bool			is_inside;
	t_param			*p;

	p = &core->param;
	is_inside = true;
	n = 0;
	while (n < MAX_ITER)
	{
		p->z_re2 = p->z_re * p->z_re;
		p->z_im2 = p->z_im * p->z_im;
		if (p->z_re2 + p->z_im2 > 4)
		{
			is_inside = false;
			break ;
		}
		count_zim_zre(p, core->fractal_type);
		n++;
	}
	*p_is_inside = is_inside;
	*p_fractal_iter = n;
}
