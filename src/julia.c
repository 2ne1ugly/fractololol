/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:01:03 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 12:30:14 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_uint	calc_color(t_uint itr)
{
	return (0x000001 * itr);
}

t_uint	calc_loop(t_coord coord, t_coord c, double dim)
{
	t_uint	itr;

	itr = 0;
	coord = complex_add(complex_pow(&coord, dim), c);
	while (itr < 255 && complex_length(&coord) <= 4)
	{
		itr++;
		coord = complex_add(complex_pow(&coord, dim), c);
	}
	return (itr);
}

t_uint	calc_loop_2(t_coord coord, t_coord c)
{
	t_uint	itr;
	double	sqr;
	double	sqi;

	itr = 0;
	sqr = coord.r * coord.r;
	sqi = coord.i * coord.i;
	while (itr < 255 && sqr + sqi < 4)
	{
   		coord.i = 2 * coord.r * coord.i + c.i;
   		coord.r = sqr - sqi + c.r;
		sqr = coord.r * coord.r;
		sqi = coord.i * coord.i;
		itr++;
	}
	return (itr);
}

void	*julia_run(void	*thread_arg)
{
	t_thread_arg	*arg;

	arg = thread_arg;
	img_pixel_put(arg->wnd, arg->i, arg->j, calc_color(calc_loop_2(
		build_coord(arg->min_r + arg->step * arg->i,
			arg->min_i + arg->step * arg->j), *((t_coord *)arg->arg))));
	return (NULL);
}

//fix multithread!
void	draw_julia(t_wnd *wnd, t_coord min, double step, t_coord c)
{
	t_thread_arg	arg;

	arg.wnd = wnd;
	arg.min_r = min.r;
	arg.min_i = min.i;
	arg.step = step;
	arg.arg = &c;
	ft_bzero(wnd->img.data_addr, wnd->width * wnd->height * wnd->img.bpp);
	run_pixels(&arg, julia_run);
	mlx_put_image_to_window(wnd->app->mlx_handle,
		wnd->wnd_handle, wnd->img.ptr, 0, 0);
}
