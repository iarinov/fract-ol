/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:31:49 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/05/31 18:37:23 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_MANDELBROT_H
# define PAINT_MANDELBROT_H

#include <unistd.h>
#include "window.h"

void paint_mandelbrot(t_core *core);
int	ft_strncmp(const char *str1, const char *str2, size_t n);

#endif
