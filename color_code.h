/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:33:46 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/29 16:47:43 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_CODE_H // rename it to mlx_my ani lo yodea
# define COLOR_CODE_H
#include "./minilibx/mlx.h"

#define LIGHT_GREEN (0x00ff77)

#define PURPLE (0x525eb4)

#define RED (0xdc3b60)

#define ORANGE (0xdd3e01)

#define BLUE (0xa1d4ff)

#define MAX_ITER (40)
// #define MIN_RE (-2.0)
// #define MAX_RE (1.0)
// #define MIN_IM (-1.2)
#define IMG_HEIGHT (400)
#define IMG_WIDTH (400)

typedef struct
{
	void *mlx_ptr;
	void *mlx_win;

	unsigned int win_width;
	unsigned int win_heigh;

}t_my_mlx;

typedef struct
{

	unsigned int x;
	unsigned int y;
}t_point;

typedef struct
{
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



#endif
