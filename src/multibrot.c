/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:10:00 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 17:02:20 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*multibrot_run(void	*local_arg)
{
	t_local_arg		*arg;
	t_uint			i;
	t_uint			j;
	t_coord			coord;
	t_uint			itr;

	arg = local_arg;
	i = arg->i;
	while (i < arg->thread_arg->wnd->height)
	{
		j = 0;
		while (j < arg->thread_arg->wnd->width)
		{
			coord = (t_coord){0, 0};
			itr = calc_loop(&coord, (t_coord){arg->thread_arg->min_r +
			arg->thread_arg->step * i, arg->thread_arg->min_i +
			arg->thread_arg->step * j}, *(int *)arg->thread_arg->render_arg);
			img_pixel_put(arg->thread_arg->wnd,	i, j, calc_color(itr, &coord,
			arg->thread_arg->wnd->mode)); 
			j++;
		}
		i += N_THREAD;
	}
	return (NULL);
}


void	draw_multibrot(t_wnd *wnd, t_coord min, double step, int dim)
{
	t_thread_arg	arg;

	arg.wnd = wnd;
	arg.min_r = min.r;
	arg.min_i = min.i;
	arg.step = step;
	arg.render_arg = &dim;
	mlx_clear_window(wnd->app->mlx_handle, wnd->wnd_handle);
	run_pixels(&arg, multibrot_run);
	mlx_put_image_to_window(wnd->app->mlx_handle,
		wnd->wnd_handle, wnd->img.ptr, 0, 0);
}
