/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:50:27 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:32:44 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			calc_color(t_uint itr, t_coord *zn, int mode)
{
	if (itr >= 255)
		return (0x010101);
	if (itr == 0)
		return (0x010101);
	if (mode == 0)
		return 0x001100 * (itr + 1 - log(log(complex_length(zn)))/log(2));
	if (mode == 1)
		return 0x000001 * (itr + 1 - log(log(complex_length(zn)))/log(2));
	if (mode == 2)
		return 0x000100 * (itr + 1 - log(log(complex_length(zn)))/log(2));
	if (mode == 3)
		return 0x010000 * (itr + 1 - log(log(complex_length(zn)))/log(2));
	return (0x010101);
}
