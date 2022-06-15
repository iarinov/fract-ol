/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:15:50 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 22:47:23 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_control.h"

# define MAN_STR	("Mandelbrot")
# define JUL_STR	("Julia")

static int	get_fractal_name(char *name)
{
	if (name == NULL)
		return(0);
	if (ft_strncmp(name, MAN_STR, 11) == 0)
		return (1);
	else if (ft_strncmp(name, JUL_STR, 6) == 0)
		return (2);
	return (0);
}

static int	digitals_notvalid(char *a, char *b)
{
	double first_param;
	double second_param;
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == '.' || (a[i] >= '0' && a[i] <= '9') || a[i] == '-')
			i++;
		else
			return (1);
	}
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == '.' || (b[i] >= '0' && b[i] <= '9') || b[i] == '-')
			i++;
		else
			return (1);
	}
	first_param = ft_atof(a);
	second_param = ft_atof(b);
	return (first_param > DBL_MAX || first_param < -DBL_MAX || second_param < -DBL_MAX || second_param > DBL_MAX);
}

int		is_valid_argument(int argc, char **argv)
{
	if (argc == 1 || get_fractal_name(argv[1]) == 0 || argc == 3)
		return (0);
	else if (argc == 4 && get_fractal_name(argv[1]) == JULIA && digitals_notvalid (argv[2], argv[3]))
		return (0);
	return (1);
}

static void	jul_param(int argc, char **argv, t_core *core)
{
	if (get_fractal_name(argv[1]) != JULIA)
		return ;
	if (argc == 2)
	{
		core->param.constant_re = -0.8;
		core->param.constant_im = 0.156;
	}
	else
	{
		core->param.constant_re = ft_atof(argv[2]);
		core->param.constant_im = ft_atof(argv[3]);
	}
	core->fractal_type = JULIA;
}

void	extract_param(int argc, char **argv, t_core *core)
{
	if (is_valid_argument(argc, argv) == 0)
		return ;
	core->fractal_type = MANDELBROT;
	jul_param(argc, argv, core);
}
