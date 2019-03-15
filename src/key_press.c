/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:55:44 by mchi              #+#    #+#             */
/*   Updated: 2019/03/05 13:23:28 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_key_press(int keycode, void *param)
{
	t_wnd	*wnd;

	wnd = param;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		wnd->changed = 1;
	if (keycode == 123)
		wnd->min.r -= wnd->step * 10;
	if (keycode == 124)
		wnd->min.r += wnd->step * 10;
	if (keycode == 125)
		wnd->min.i += wnd->step * 10;
	if (keycode == 126)
		wnd->min.i -= wnd->step * 10;
	if (keycode == 53)
		exit(0);
	return (0);
}
