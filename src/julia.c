/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:01:03 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 17:04:01 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_uint	calc_loop(t_coord *coord, t_coord c, int dim)
{
	t_uint	itr;

	if (dim == 2)
		return calc_loop_2(coord, c);
	itr = 0;
	*coord = complex_pow(coord, dim);
	complex_add(coord, c);
	while (itr < 255 && complex_length(coord) <= 4)
	{
		itr++;
		*coord = complex_pow(coord, dim);
		complex_add(coord, c);
	}
	return (itr);
}

t_uint	calc_loop_2(t_coord *coord, t_coord c)
{
	t_uint	itr;
	double	sqr;
	double	sqi;

	itr = 0;
	sqr = coord->r * coord->r;
	sqi = coord->i * coord->i;
	while (itr < 255 && sqr + sqi < 4)
	{
   		coord->i = 2 * coord->r * coord->i + c.i;
   		coord->r = sqr - sqi + c.r;
		sqr = coord->r * coord->r;
		sqi = coord->i * coord->i;
		itr++;
	}
	return (itr);
}

void	*julia_run(void	*local_arg)
{
	t_local_arg	*arg;
	t_uint		i;
	t_uint		j;
	t_coord		coord;
	t_uint		itr;

	arg = local_arg;
	i = arg->i;
	while (i < arg->thread_arg->wnd->height)
	{
		j = 0;
		while (j < arg->thread_arg->wnd->width)
		{
			coord = (t_coord){arg->thread_arg->min_r + arg->thread_arg->step * i,
				arg->thread_arg->min_i + arg->thread_arg->step * j};
			itr = calc_loop(&coord, *(t_coord *)arg->thread_arg->render_arg, 2);
			img_pixel_put(arg->thread_arg->wnd, i, j, calc_color(itr, &coord,
			arg->thread_arg->wnd->mode));
			j++;
		}
		i += N_THREAD;
	}
	return (NULL);
}

void	draw_julia(t_wnd *wnd, t_coord min, double step, t_coord c)
{
	t_thread_arg	arg;

	arg.wnd = wnd;
	arg.min_r = min.r;
	arg.min_i = min.i;
	arg.step = step;
	arg.render_arg = &c;
	ft_bzero(wnd->img.data_addr, wnd->width * wnd->height * wnd->img.bpp);
	run_pixels(&arg, julia_run);
	mlx_put_image_to_window(wnd->app->mlx_handle,
		wnd->wnd_handle, wnd->img.ptr, 0, 0);
}
