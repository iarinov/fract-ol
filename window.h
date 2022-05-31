/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:15:10 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/31 21:31:06 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H


#define MAX_ITER (40)
// #define MIN_RE (-2.0)
// #define MAX_RE (1.0)
// #define MIN_IM (-1.2)
#define IMG_HEIGHT (400)
#define IMG_WIDTH (400)



typedef struct
{
	void *mlx_win;
	void *mlx_ptr;

	unsigned int win_width;
	unsigned int win_heigh;

}t_my_mlx;


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
	double z_re;
	double z_im;


}t_param;

typedef struct
{
	t_my_mlx mlx_main;
	t_param param;
}t_core;


int handle_key (int keycode, t_core *core);
int clean (t_core *core);
int	mouse_move(int keycode, int x, int y, t_core *core);

#endif



