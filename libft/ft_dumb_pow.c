/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumb_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:28:48 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:28:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_dumb_pow(double x, int y)
{
	double result;

	result = 1;
	while (y > 0)
	{
		result *= x;
		y--;
	}
	while (y < 0)
	{
		result /= x;
		y++;
	}
	return (result);
}
