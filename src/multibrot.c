/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:10:00 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 12:19:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_multibrot(t_wnd *wnd, t_coord min, double step, double dim)
{
	t_uint i;
	t_uint j;

	ft_bzero(wnd->img.data_addr, wnd->width * wnd->height * wnd->img.bpp);
	i = 0;
	while (i < wnd->height)
	{
		j = 0;
		while (j < wnd->width)
		{
			if (dim == 2)
				img_pixel_put(wnd, i, j, calc_color(calc_loop_2(
					build_coord(0, 0),
					build_coord(min.r + step * i, min.i + step * j))));
			else
				img_pixel_put(wnd, i, j, calc_color(calc_loop(
					build_coord(0, 0),
					build_coord(min.r + step * i, min.i + step * j), dim)));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(wnd->app->mlx_handle,
		wnd->wnd_handle, wnd->img.ptr, 0, 0);
}
