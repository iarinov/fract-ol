/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:04:57 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 22:07:35 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "window.h"

int	get_classic(int n)
{
	int	color[16];

	if (n > 15 || n < 0)
	{
		return (0);
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

void	put_color(const t_core *core, int color)
{
	char	*pos;

	pos = core->mlx_main.mlx_data_addr + (core->param.y * core->param.line_len
			+ core->param.x * (core->param.bpp / 8));
	*(int *)pos = color;
}


void	set_color(t_core *core, const unsigned int fractal_iter,
						const bool is_inside)
{
	int	color;

	color = 0xfffafa;
	core->param.z_re2 = core->param.z_re * core->param.z_re;
	core->param.z_im2 = core->param.z_im * core->param.z_im;
	if (is_inside)
		color = ceil(sqrt(core->param.z_im2 + core->param.z_re2) * 8.0);
	else
		color = (int)(fractal_iter) % 16;
	color = get_classic(color);
	put_color(core, color);
}
