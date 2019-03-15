/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:33:01 by mchi              #+#    #+#             */
/*   Updated: 2019/02/13 02:57:02 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate(const char *str, int sign)
{
	long int value;

	value = 0;
	while ('0' <= *str && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		if (value > 2147483648 && sign == -1)
			return (0);
		if (value > 2147483647 && sign == 1)
			return (-1);
		str++;
	}
	return ((int)(value * sign));
}

int			ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r'))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	return (calculate(str, sign));
}
