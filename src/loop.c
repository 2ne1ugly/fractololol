/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:02:41 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:20:41 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			app_loop(void *param)
{
	t_app	*app;
	t_wnd	*wnd;

	app = param;
	wnd = app->exposed_wnd;
	if (wnd->changed == 1)
	{
		if (ft_strcmp(wnd->name, "julia") == 0)
			draw_julia(wnd, wnd->min, wnd->step, wnd->c);
		else
			draw_multibrot(wnd, wnd->min, wnd->step, wnd->dim);
		wnd->changed = 0;
	}
	return (0);
}
