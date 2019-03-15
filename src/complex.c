/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:23:56 by mchi              #+#    #+#             */
/*   Updated: 2019/03/05 12:51:21 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_length(t_coord *coord)
{
	return (sqrt(pow(coord->r, 2) + pow(coord->i, 2)));
}

t_coord	complex_pow(t_coord *coord, double dim)
{
	t_coord output;
	double	theta;
	double	multiple;

	theta = atan2(coord->i, coord->r);
	multiple = pow(complex_length(coord), dim);
	output.r = multiple * cos(dim * theta);
	output.i = multiple * sin(dim * theta);
	return (output);
}

t_coord	complex_add(t_coord lhs, t_coord rhs)
{
	lhs.r += rhs.r;
	lhs.i += rhs.i;
	return (lhs);
}

t_coord build_coord(double r, double i)
{
	t_coord	coord;

	coord.r = r;
	coord.i = i;
	return (coord);
}
