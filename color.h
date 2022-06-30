/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:04 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 10:51:41 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "window.h"

void	set_color(t_core *core, const unsigned int fractal_iter,
			const bool is_inside);
void	put_color(const t_core *core, int color);

#endif
