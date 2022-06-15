/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:38:26 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/15 16:01:22 by aiarinov         ###   ########.fr       */
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
	int		n;
	int		i;
	int		mult;
	int		counter;
	double	res;
	int		is_after_dot;

	n = 0;
	i = ft_atoi_point(str);
	mult = 1;
	counter = 0;
	is_after_dot = 0;
	while (str[n] != '\0')
	{
		if (str[n] == '.')
			is_after_dot = 1;
		if (is_after_dot == 1 && str[n] <= '9' && str[n] >= '0')
			counter++;
		n++;
	}
	if (counter > 0)
	{
		counter--;
		mult = pow(10, counter);
		res = i * (0.1 / mult);
	}
	else
		res = i;
	return (res);
}
