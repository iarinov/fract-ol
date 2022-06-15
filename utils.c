/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:38:26 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 22:43:13 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi_point(const char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str == '.')
			str++;
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			break ;
		str++;
	}
	return (sign * sum);
}

double	ft_atof(char *str)
{
	int		i;
	int		counter;
	double	res;
	int		is_after_dot;

	i = ft_atoi_point(str);
	counter = 0;
	is_after_dot = 0;
	while (*str != '\0')
	{
		if (*str == '.')
			is_after_dot = 1;
		if (is_after_dot == 1 && *str <= '9' && *str >= '0')
			counter++;
		str++;
	}
	if (counter > 0)
		res = i * (0.1 / pow(10, counter - 1));
	else
		res = i;
	return (res);
}
