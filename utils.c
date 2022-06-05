/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:38:26 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/06/05 16:55:17 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
int ft_atoi_point(const char *str)
{
	int sum;
	int sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\r' || *str == '\v')
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
			break;
		str++;
	}
	return (sign * sum);
}

double ft_atof(char *str)
{
	int n = 0;
	int i = ft_atoi_point(str);
	int mult = 1;
	int counter = 0;
	double res;
	char is_after_dot = 0;
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
