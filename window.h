/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:15:10 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/05 16:50:23 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

#define MAX_ITER (20)
#define IMG_HEIGHT (400)
#define IMG_WIDTH (400)
#define JULIA (2)
#define MANDELBROT (1)

typedef struct
{
	void *mlx_win;
	void *mlx_ptr;
	void *mlx_img;
	char *mlx_data_addr;

	unsigned int win_width;
	unsigned int win_heigh;

} t_my_mlx;

typedef struct
{
	unsigned int x;
	unsigned int y;
	double zoom;
	double horis;
	double vert;
	double max_im;
	double max_re;
	double min_im;
	double min_re;
	double re_factor;
	double im_factor;
	double c_re;
	double c_im;
	double constant_re;
	double constant_im;
	double z_re;
	double z_im;
	int bpp;
	int line_len;
	int endian;

} t_param;

typedef struct
{
	t_my_mlx mlx_main;
	t_param param;
	int fractal_type;
} t_core;

int handle_key(int keycode, t_core *core);
int clean(t_core *core);
int mouse_move(int keycode, int x, int y, t_core *core);
int destroy(t_core *core);

#endif
