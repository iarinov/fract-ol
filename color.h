/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:04 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 22:34:43 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "window.h"

void	set_color(t_core *core, const unsigned int fractal_iter,
						const bool is_inside);
void	put_color(const t_core *core, int color);


#endif
