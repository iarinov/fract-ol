/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:31:49 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/01 13:19:40 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_MANDELBROT_H
# define PAINT_MANDELBROT_H

#include <unistd.h>
#include "window.h"

void paint_mandelbrot(t_core *core);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
void paint_julia(t_core *core);

#endif
