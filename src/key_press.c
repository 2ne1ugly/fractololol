/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:55:44 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:20:31 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

int	mandelia_key_press(int keycode, void *param)
{
	t_wnd	*wnd;

	wnd = param;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126 ||
		(18 <= keycode && keycode <= 21))
		wnd->changed = 1;
	if (18 <= keycode && keycode <= 21)
		wnd->mode = keycode - 18;
	if (keycode == 123)
		wnd->min.r -= wnd->step * 50;
	if (keycode == 124)
		wnd->min.r += wnd->step * 50;
	if (keycode == 125)
		wnd->min.i += wnd->step * 50;
	if (keycode == 126)
		wnd->min.i -= wnd->step * 50;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	multibrot_key_press(int keycode, void *param)
{
	t_wnd	*wnd;

	wnd = param;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126 ||
		(18 <= keycode && keycode <= 21) || keycode == 27 || keycode == 24)
		wnd->changed = 1;
	if (18 <= keycode && keycode <= 21)
		wnd->mode = keycode - 18;
	if (keycode == 123)
		wnd->min.r -= wnd->step * 50;
	if (keycode == 124)
		wnd->min.r += wnd->step * 50;
	if (keycode == 125)
		wnd->min.i += wnd->step * 50;
	if (keycode == 126)
		wnd->min.i -= wnd->step * 50;
	if (keycode == 27 && wnd->dim > 1)
		wnd->dim--;
	if (keycode == 24)
		wnd->dim++;
	if (keycode == 53)
		exit(0);
	return (0);
}
