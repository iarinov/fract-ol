/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:33:46 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/29 12:38:21 by annaiarinov      ###   ########.fr       */
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

typedef struct
{
	void *mlx_ptr;
	void *mlx_win;

	// unsigned int win_width;
	// unsigned int win_heigh;

}t_my_mlx;

typedef struct
{
	unsigned int x;
	unsigned int y;
}t_point;


#endif
