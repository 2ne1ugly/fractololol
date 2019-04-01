/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:23:56 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:27:22 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_length(t_coord *coord)
{
	return (sqrt(pow(coord->r, 2) + pow(coord->i, 2)));
}

t_coord	complex_pow(t_coord *coord, int dim)
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

void	complex_add(t_coord *lhs, t_coord rhs)
{
	lhs->r += rhs.r;
	lhs->i += rhs.i;
}
