/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:16:37 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/16 11:28:31 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CONTROL_H
# define INPUT_CONTROL_H

# include "window.h"
# include "utils.h"

# define MAN_STR	("Mandelbrot")
# define JUL_STR	("Julia")

# define INSTRUCTIONS	("-> Use: ./fractol [name] [num.num]\n \
		[num.num] is a floating point number ('.' - delimeter).\n \
		- [Mandelbrot] for Mandelbrot set\n - [Julia] for Julia set\n \
		For [Mandelbrot] NO additional parameters possible\n \
		For [Julia] either none OR 2 parameters possible.\n \
		Use arrows - + q and mouse during the evaluation\n")

int		is_valid_argument(int argc, char **argv);
void	extract_param(int argc, char **argv, t_core *core);

#endif
