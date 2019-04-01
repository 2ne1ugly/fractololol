/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:02:37 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:18:48 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	julia_mouse_move(int x, int y, void *param)
{
	t_wnd	*wnd;

	wnd = param;
	wnd->c = (t_coord){x * 0.001, y * 0.001};
	wnd->changed = 1;
	return (0);
}

void 	calc_zoom(int x, int y, double new_step, t_wnd *wnd)
{
	wnd->min.r -= x * (new_step - wnd->step);
	wnd->min.i -= y * (new_step - wnd->step);
	wnd->step = new_step;
}

int 	mandelia_mouse_press(int button, int x, int y, void *param)
{
	t_wnd	*wnd;

	(void)x;
	(void)y;
	wnd = param;
	if (x >= 0 && x < (int)wnd->width && y >= 0 && y < (int)wnd->height)
	{
		if (button == 5)
			calc_zoom(x, y, wnd->step * 1.03, wnd);
		if (button == 4)
			calc_zoom(x, y, wnd->step / 1.03, wnd);
		wnd->changed = 1;	
	}
	return (0);
}

int 	multibrot_mouse_press(int button, int x, int y, void *param)
{
	t_wnd	*wnd;

	(void)x;
	(void)y;
	wnd = param;
	if (x >= 0 && x < (int)wnd->width && y >= 0 && y < (int)wnd->height)
	{
		if (button == 5)
			calc_zoom(x, y, wnd->step * 1.03, wnd);
		if (button == 4)
			calc_zoom(x, y, wnd->step / 1.03, wnd);
		wnd->changed = 1;
	}
	return (0);
}